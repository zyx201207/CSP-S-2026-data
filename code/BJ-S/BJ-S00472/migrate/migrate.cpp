#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll C,T;
ll N,D;
const ll kMax=500,Max_val=2e14;
ll a[kMax+5],p[kMax+5][kMax+5],s[kMax+5][kMax+5];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>N>>D;
        for(ll i=1;i<=N;i++){
            cin>>a[i];
        }
        ll ans=0;
        for(ll i=1;i<=N;i++){
            for(ll j=1;j<=N;j++){
                s[i][j]=Max_val;
                p[i][j]=0;
            }
        }
        for(ll i=1;i<=N;i++){
            p[i][i]=1;
            s[i][i]=0;
            for(ll j=i;j<=N;j++){
                for(ll k=j-1;k>=i;k--){
                    if(a[j]-a[k]>D){
                        break;
                    }
                    s[i][j]=min(s[i][j],s[i][k]+1);
                }
                for(ll k=j-1;k>=i;k--){
                    if(a[j]-a[k]>D){
                        break;
                    }
                    if(s[i][j]==s[i][k]+1){
                        p[i][j]+=p[i][k];
                    }
                }
                if(p[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
