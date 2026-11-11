#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,ll>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+5;
const ll inf=1e18;
int c,n,m,d,q;
int num,a;
int in[N],cnt[N];
int id[N][25];
ll t[N][25],dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>in[i];
    rep(i,1,n){
        cin>>num;
        rep(j,1,num){
            cin>>a;
            id[a][++cnt[a]]=i;
            cin>>t[a][cnt[a]];
        }
    }
    rep(i,1,n){
        rep(j,1,n){
            if(i!=j) dis[i][j]=inf;
        }
    }
    rep(i,1,m){
        rep(j,1,cnt[i]){
            rep(k,j+1,cnt[i]){
                int u=id[i][j],v=id[i][k];
                dis[u][v]=dis[v][u]=t[i][j]+t[i][k];
            }
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                if(i==j) continue;
                ll now=dis[i][k]+dis[k][j];
                if(now<dis[i][j]) dis[i][j]=now;
            }
        }
    }
    // rep(i,1,n){
    //     rep(j,i+1,n){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        rep(i,1,cnt[x]){
            rep(j,1,cnt[y]){
                int u=id[x][i],v=id[y][j];
                ll now=t[x][i]+t[y][j]+dis[u][v];
                if(now<ans) ans=now;
            }
        }
        cout<<in[x]+in[y]+ans<<'\n';
    }
    return 0;
}