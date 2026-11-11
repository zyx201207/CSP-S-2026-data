#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
long long ans;
int dtz[N],ck[N];
//int a[505][N],t[505][N];
long long floyd[M][M];
vector<int>a[N],t[N];
vector<pair<int ,int > > dt[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ck[i];
	}
	for(int pos=1;pos<=n;pos++){
		int k;
		cin>>k;
		a[pos].push_back(0);
		t[pos].push_back(0);
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			a[pos].push_back(x);
			t[pos].push_back(y);
//			cin>>a[pos][i]>>t[pos][i];
			dt[a[pos][i]].push_back(make_pair(pos,i));
		}
	}
	memset(floyd,0x3f,sizeof(floyd));
	for(int k=1;k<=m;k++){
		int len=dt[k].size();
		for(int i=0;i<len;i++){
			int u=dt[k][i].first;
			int jju=dt[k][i].second;
			for(int j=0;j<len;j++){
				if(i==j) continue;
				int v=dt[k][j].first;
				int jjv=dt[k][j].second;
				floyd[u][v]=min(floyd[u][v],(long long)(t[u][jju]+t[v][jjv]));
			}
		}
	}
	for(int i=1;i<=n;i++) floyd[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<floyd[i][j]<<" ";
//		}cout<<"\n";
//	}
	while(q--){
		int x,y;
		ans=LONG_LONG_MAX;
		cin>>x>>y;
		int len1=dt[x].size();
		int len2=dt[y].size();
		for(int i=0;i<len1;i++){
			int u=dt[x][i].first;
			int jju=dt[x][i].second;
			for(int j=0;j<len2;j++){
				int v=dt[y][j].first;
				int jjv=dt[y][j].second;
				ans=min(ans,floyd[u][v]+t[u][jju]+t[v][jjv]);
			}
		}
		cout<<ans+ck[x]+ck[y]<<"\n";
	}
	return 0;
}
/*
化线路为点
然后跑一边floyd
最后遍历一遍就可以了吧
理论复杂度：
md^2+n^3+qd^2;
会赢吗 
会赢的 

数组开不到5e5*500?
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
