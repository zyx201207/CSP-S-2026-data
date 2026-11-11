#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+10;
ll c,n,m,d,q;
ll w[M];
ll subs[M][30],lens[M][30],cntsb[M];
ll dist[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=500;i++){
        for(ll j=1;j<=500;j++){
                if(i==j){
                    dist[i][j]=0;
                }else{dist[i][j]=1e14;
                }

        }
    }
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll k,a,t;
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a>>t;
            subs[a][++cntsb[a]]=i;
            lens[a][cntsb[a]]=t;
        }
    }
    for(ll i=1;i<=m;i++){
        ll cd=cntsb[i];
        for(ll j=1;j<=cd;j++){
            for(ll k=j+1;k<=cd;k++){
                ll x=subs[i][j],y=subs[i][k];
                dist[x][y]=dist[y][x]=min(dist[x][y],lens[i][j]+lens[i][k]);
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=w[x]+w[y],dew=1e14;
        ll cx=cntsb[x],cy=cntsb[y];
        for(ll i=1;i<=cx;i++){
            for(ll j=1;j<=cy;j++){
                dew=min(dew,dist[subs[x][i]][subs[y][j]]+lens[x][i]+lens[y][j]);
            }
        }
        cout<<ans+dew<<endl;
    }
    return 0;
}
