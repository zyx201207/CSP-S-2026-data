#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
long long n,m,a[N],ca[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(i!=1){
            ca[i]=a[i]-a[i-1];
        }
    }
    long long l=1,r=1,maxxx=1,sum=0;
    for(r=2;r<=n;r++){
        sum+=ca[r]*(r-l);
        while(sum>m){
            sum-=(a[r]-a[l]);
            l++;
        }
        maxxx=max(maxxx,r-l+1);
    }
    cout<<maxxx<<endl;
    return 0;
}
