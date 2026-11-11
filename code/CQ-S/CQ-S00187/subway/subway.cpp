#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll w[500005],len[505][505];
vector<pair<int,int> > all[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i],all[i].reserve(d);
	memset(len,0x3f,sizeof(len));
	for(int i=1;i<=n;i++){
		len[i][i]=0;
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			all[a].push_back({i,t});
		}
	}
	int u,v,x;
	for(int i=1;i<=m;i++){
		for(int j=0;j<all[i].size();j++){
			for(int k=j+1;k<all[i].size();k++){
				u=all[i][j].first,v=all[i][k].first,x=all[i][j].second+all[i][k].second;
				len[v][u]=len[u][v]=min(len[u][v],(ll)x);
			}
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
	while(q--){
		cin>>u>>v;
		ll ans=LLONG_MAX;
		for(auto& i:all[u])for(auto& j:all[v])ans=min(ans,len[i.first][j.first]+i.second+j.second);
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
/*
20*n^2的建图，然后跑floyd就完了
算了写dij不碍事
不对这图稠密死了
那还不如就跑floyd呢
？？？
我好像看反了n和m了
m才是点数
重推
考虑建m个虚点
额这很t2
然后记虚点之间的最短路
查询枚举起点和终点的虚点 
*/
