#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,d,q,x,y;
int b[500001],c[501];
long long f[501][501];
vector<pair<int,int> > v[501],p[500001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++){
			cin>>x>>y;
			v[i].push_back({x,y});
			p[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int u=1;u<=n;u++){
		f[u][u]=0;
		for(auto md:v[u]){
			int w1=md.second,x=md.first;
			for(auto dm:p[x]){
				int w2=dm.second,v=dm.first;
				if(u==v) continue;
				f[u][v]=f[v][u]=min(f[u][v],(long long)w1+w2);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(f[i][j]>20) cout<<0<<" ";
//			else cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min({f[i][j],f[i][k]+f[k][j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long ans=LLONG_MAX;
		for(auto u:p[x]){
			for(auto v:p[y]){
				ans=min(ans,(long long)u.second+f[u.first][v.first]+(long long)v.second);
			}
		}
		cout<<ans+b[x]+b[y]<<"\n";
	}
	return 0;
}
/*
题有点难懂啊

现在是 15:09，理清楚了

注意到每个点的度只有 20，计算可以暴力枚举。

然后站台间直接玩个 floyd 就行？？？这么水吗 

现在是 15:12 开始工作。 

15:32 写完了，不愧是最短路之神呐。

差点忘吸氧了。 
*/

