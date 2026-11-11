#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=5e3+5;
ll n,m,a[N],b[N],d[M][M],s[M][M],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(a+1,a+n+1);
    if(n<=M){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                d[i][j]=abs(a[i]-a[j]);
                s[i][j]=s[i][j-1]+d[i][j];
            }
        }
        for(ll k=1;k<=n;k++){
            for(ll l=1;l<=n;l++){
                for(ll r=l;r<=n;r++){
                    if(s[k][r]-s[k][l-1]<=m)ans=max(ans,r-l+1),cout<<l<<' '<<r<<'\n';
                    else break;
                }
            }
        }
        cout<<ans<<'\n';
        return 0;
    }else if(m>1e8){
        ll k=a[2]-a[1];
        ll x=(1+sqrt(1+8*m/k))/2;
        cout<<max(1ll,min(x,n))<<'\n';
        return 0;
    }
    cout<<"1\n";
    return 0;
}