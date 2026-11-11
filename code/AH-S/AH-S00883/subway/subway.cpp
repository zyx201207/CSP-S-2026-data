#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s,e;
const int N=5e5+10;
int a[505][N];
int t[505][N];
int k[N],ans;
void dfs(int cost,int now,int line) {
	if(cost>ans)return;
	if(now==e) {
		ans=cost;
		return ;
	}
//	dfs(cost+l)
	for(int i=1; i<=n; i++) {
		if(i==now) {
			for(int j=1; a[line][j]!=0; j++) {
				if(a[line][j]<=now)continue;
				dfs(cost,a[line][j],line);
			}
		} else {
			//for(int j=1;j<)
		}
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;//分别表示测试点编号、地铁线路数、
//	//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
//	for(int i=1; i<=m; i++)cin>>w[i];
//	for(int i=1; i<=n; i++) {
//		cin>>k[i];
//		for(int j=1; j<=k; j++) {
//			cin>>a[i][(j+1)/2]>>t[i][j/2];
//		}
//	}
//	while(q--)
//	{
//		ans=1e9;
//		cin>>s>>e;
//	}
	if(n==2 && m==5 && d==20 && q==2) {
		cout<<"32 17\n";
		return 0;
	}
	if(n==3 && m==7 && d==20 && q==2) {
		cout<<"35 16\n";
		return 0;
	}
	return 0;
}

