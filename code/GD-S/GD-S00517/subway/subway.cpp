#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k,a,t,x,y,f[505][505];
struct o{
	int id,w;
};
vector<o>v[500005];
vector<int>hh[505];
priority_queue<int,vector<int>,greater<int> >qe;
signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,63,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++){
				f[v[i][j].id][v[i][k].id]=f[v[i][k].id][v[i][j].id]=min(f[v[i][j].id][v[i][k].id],v[i][j].w+v[i][k].w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>x>>y;
		int cnt=w[x]+w[y],ans=1e17;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,cnt+v[x][i].w+v[y][j].w+f[v[x][i].id][v[y][j].id]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
