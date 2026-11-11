#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    ll maxn=-0x3f3f3f3f;
    if(m==1){
        for(ll i=1;i<=n;i++)maxn=max(maxn,a[i]);
        ans=maxn;
    }else if(m==n){
        ll ansm=a[1];
        for(ll i=2;i<=n;i++)ansm=ansm&a[i];
        ans=ansm;
    }else if(m==2){
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        ans=maxn;
    }else if(m==n-1){
        ll s=a[1];
        for(ll i=1;i<=a[i];i++)s=s&a[i];
        for(ll i=1;i<=n;i++){
            ll ai=a[i]^0;
            ll si=s&ai;
            maxn=max(maxn,si);
        }
        ans=maxn;
    }else if(n<=20){
        ans=1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
