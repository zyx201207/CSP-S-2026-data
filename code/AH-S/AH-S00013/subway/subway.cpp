#include<bits/stdc++.h>
using namespace std;
using int64=long long;
using prii=pair<int,int>;
const int N=505,M=2e5+5;
const int64 INF=1<<13;
int c,n,m,d,q;
int64 w[N],dist[N][N],side;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dist[i][j]=INF;
    for(int i=1;i<=n;++i) cin>>w[i];
    if(7<=c&&c<=11){
        int64 a,b,ta,tb;
        for(int i=1,k;i<=m;++i){
            cin>>k;
            cin>>a>>ta;
            if(k==1) break;
            cin>>b>>tb;
            dist[a][b]=dist[b][a]=min(dist[a][b],ta+tb);
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    if(dist[i][k]!=INF&&dist[k][j]!=INF&&i!=k&&j!=k)
                    dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int s,t;
        while(q--){
            cin>>s>>t;
            cout<<w[s]+w[t]+dist[s][t]<<'\n';
        }
    }else{
        for(int i=1;i<=m;++i){
            int k;cin>>k;
            vector<prii>tmp;
            for(int j=0,a,t;j<k;++j){
                cin>>a>>t;
                for(auto p:tmp){
                    int64 val=p.second+t;
                    dist[p.first][a]=dist[a][p.first]=min(dist[p.first][a],val);
                }tmp.push_back({a,t});
            }
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    if(dist[i][k]!=INF&&dist[k][j]!=INF&&i!=k&&j!=k)
                    dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int s,t;
        while(q--){
            cin>>s>>t;
            cout<<w[s]+w[t]+dist[s][t]<<'\n';
        }
    }
	return 0;
}
