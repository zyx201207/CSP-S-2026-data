#include <bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M];
long long res,f[N][N];
vector<pair<int,long long>> mem[M];
inline void file(){freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> n >> m >> d >> q,memset(f,0x3f,sizeof(f));
    for(int i(1);i<=m;++i) cin >> w[i];
    for(int i(1),k;i<=n;++i){
        cin >> k,f[i][i]=0;
        for(int j(1),a,t;j<=k;++j) cin >> a >> t,mem[a].push_back({i,t});
    }
    for(int i(1);i<=m;++i) for(int j(1);j<mem[i].size();++j) for(int k(0);k<j;++k) f[mem[i][k].first][mem[i][j].first]=f[mem[i][j].first][mem[i][k].first]=min(f[mem[i][j].first][mem[i][k].first],mem[i][j].second+mem[i][k].second);
    for(int i(1);i<=n;++i) for(int j(1);j<=n;++j) for(int k(1);k<=n;++k) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i(0),x,y;i<q;++i){
        cin >> x >> y,res=inf;
        for(pair<int,int> s:mem[x]) for(pair<int,int> t:mem[y]) res=min(res,f[s.first][t.first]+w[x]+w[y]+s.second+t.second);
        cout << res << '\n';
    }
    return 0;
}