#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int c,n,m,d,q;
int w[MAXN],k[MAXN],a[505][MAXN],t[505][MAXN];
//每个地铁站的地铁口走到站厅需要的时间
//表示第i条线路经过的地铁站数
//a i,j 表示第 i 条线路经过的第j 个地铁站
//t i,j 表示从该地铁站的站厅走到第i条线路的站台需要的时间
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
//测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		long long ans = 0;
		int x,y; cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					ans += w[x]+t[i][j];
					x = a[i][j+1];
					if(x==y) break;
					i=1,j=1;
				} 
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
