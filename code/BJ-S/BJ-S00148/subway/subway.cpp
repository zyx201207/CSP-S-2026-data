#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
const int N=505,M=5e5+5;
int n,m,d,q,c[M];
ll dis[N][N];
vector<pii>v[M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int AC;cin>>AC;
    memset(dis,0x3f,sizeof dis);
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            v[x].pb((pii){y,i});
        }
    }
    for(int i=1;i<=m;i++){
        for(pii j:v[i]){
            for(pii k:v[i]){
                dis[j.se][k.se]=min(dis[j.se][k.se],(ll)j.fi+k.fi);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        ll ans=1e18;
        if(s==e){
            cout<<"0\n";
            continue;
        }
        for(pii i:v[s]){
            for(pii j:v[e]){
                ans=min(ans,dis[i.se][j.se]+j.fi+i.fi);
            }
        }
        ans+=c[s]+c[e];
        cout<<ans<<'\n';
    }
    return 0;
}