#include<iostream>
#include<vector>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=5e5+5;
const ll inf=1e15;

int c,n,m,q;
vector<pii>e[maxn];
int w[maxn];
ll f[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>c>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            e[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)f[i][j]=(i!=j)*inf;
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++)
            for(int k=0;k<j;k++){
                int u=e[i][j].fs,v=e[i][k].fs;
                f[u][v]=f[v][u]=min(f[u][v],0ll+e[i][j].sc+e[i][k].sc);
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<j;k++)f[j][k]=f[k][j]=min(f[j][k],f[j][i]+f[i][k]);
    while(q--){
        int u,v;
        cin>>u>>v;
        ll s=w[u]+w[v],ans=inf;
        for(pii i:e[u])
            for(pii j:e[v])ans=min(ans,i.sc+j.sc+f[i.fs][j.fs]);
        cout<<s+ans<<'\n';
    }
    return 0;
}
