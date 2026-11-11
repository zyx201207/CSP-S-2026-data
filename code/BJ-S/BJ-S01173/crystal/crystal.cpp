#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500000;
int n,m,a[N+10],s[N+10];

bool check(int x){
    for(int i=x;i<=n;i++){
        int l=i-x+1,r=i;
        if(s[r]-(s[l]+(a[r]-a[l])*(l-1))<=m){
            return 1;
        }
    }
    return 0;
}

int binary(int l,int r){
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return r;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    cout<<binary(1,n);
    return 0;
}
//g++ crystal.cpp -o a -g -std=c++14 -O2 -static -Wall -Wextra
//ulimit -s unlimited
//bt step next