#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
ll n,m,maxn=-1;
void xh(ll m,ll x,ll ly){
    if(m>=0&&x<n)
    for(int i=x;i<=n;i++){
        xh(m-1,x+1,ly&a[i]);
    }
    else {
        maxn=max(maxn,ly);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(m==1){
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        cout<<maxn;
    }else if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }else{
        xh(m,1,1<<30);
        cout<<maxn;
    }
    return 0;
}
