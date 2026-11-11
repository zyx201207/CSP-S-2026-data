#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n;
ll m,a[500005],sum[500005];

bool check(int k){
    for(int i=k;i<=n;i++){
        if(a[i]*k-sum[i]+sum[i-k]<=m){
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,mid;
    while(l<r){
        mid=l+r+1>>1;
//        cout<<mid<<" ";
        if(check(mid)){
            l=mid;
//            cout<<"1\n";
        }
        else{
            r=mid-1;
//            cout<<"0\n";
        }
    }
    cout<<l;
    return 0;
}
