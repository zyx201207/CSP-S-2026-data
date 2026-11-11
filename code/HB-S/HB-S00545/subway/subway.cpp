#include<bits/stdc++.h> 
#define ll long long
#define INF 100000000000000000
using namespace std; 
const int N=505,M=500005;
int cid,n,m,d,Q;
ll w[M],f[N][N];
vector<pair<int,ll> > e[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>cid>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=INF;
    for(int i=1;i<=n;i++){
        int len;cin>>len;
        while(len--){
            int x,y;
            cin>>x>>y;
            e[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        int len=e[i].size();
        len--;
        for(int j=0;j<=len;j++) for(int k=0;k<=len;k++){
            f[e[i][j].first][e[i][k].first]=min(f[e[i][j].first][e[i][k].first],e[i][j].second+e[i][k].second);
        }
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(Q--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<"0\n";
            continue;
        }
        int len1=e[x].size()-1,len2=e[y].size()-1;
        ll ans=INF;
        for(int i=0;i<=len1;i++) for(int j=0;j<=len2;j++){
            ans=min(ans,w[x]+w[y]+f[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
        }
        cout<<ans<<"\n";
    }
    return  0;
}