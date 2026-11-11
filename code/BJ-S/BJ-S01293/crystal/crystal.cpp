#include<bits/stdc++.h>
using namespace std;
long long a[500025],sum[500025];
long long n,m,mina=1e18,maxa=-1e18;
bool check(int x){
    for(int i=x;i<=n;i++){
        if(1LL*a[i]*(x-1)-(sum[i-1]-sum[i-x])<=m){
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
        mina=min(mina,a[i]);
        maxa=max(maxa,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
