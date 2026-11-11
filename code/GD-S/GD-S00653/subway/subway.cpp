#include<bits/stdc++.h>
#define int long long

using namespace std;

int _,n,m,d,q;
int x,w;
int N;
int t[500002];
//int k[502];
int a[502][502];//存时间 
vector<pair<int,int> > mp[500001];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
//	scanf("%d%d%d%d%d",&_,&n,&m,&d,&q);
	cin>>_>>n>>m>>d>>q;
	//线路数，站台数，站台最多经过，询问。 
	for(int i = 1; i <= m; i ++ ){
		cin>>t[i];
	}
	for(int i = 1; i <= n; i ++ ){//第i个站台 
		cin>>N;
		for(int j = 1; j <= N; j ++ ){
			cin>>x>>w; 
			mp[x].push_back({i,w});//第x个站厅到第i条线路站台的时间 
			//mp[x][i]表示经过x这个站的所有线路的编号和换乘时间 
		}
	}
	for(int i = 1; i <= m; i ++ ){//枚举每个站台 
		for(int j = 0; j < mp[i].size(); j ++ ){//第一条线路 
			for(int k = j+1; k < mp[i].size(); k ++ ){//第二条线路 
				a[mp[i][j].first][mp[i][k].first] = min(a[mp[i][j].first][mp[i][k].first],mp[i][j].second + mp[i][k].second);
				a[mp[i][k].first][mp[i][j].first] = a[mp[i][j].first][mp[i][k].first];
			}
		}
	}
	
	for(int i = 1; i <= n; i ++ )a[i][i] = 0;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= n; j ++ ){
			for(int k = 1; k <= n; k ++ ){
				a[j][k] = min(a[j][k],a[j][i] + a[i][k]);
			}
		}
	}
//	for(int i = 1; i <= n; i ++ ){
//		for(int j = 1; j <= n; j ++ ){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(int i = 1; i <= q; i ++ ){
		int u,v;
		cin>>u>>v;
		int ans = a[501][501];
		//枚举过u的所有线路
		for(int i = 0; i < mp[u].size(); i ++ ){
			int lu = mp[u][i].first;
			for(int j = 0; j < mp[v].size(); j ++ ){
				int lv = mp[v][j].first;
//				cout<<lu<<" "<<lv<<"\n"; 
				ans = min(ans,t[u] + mp[u][i].second + a[lu][lv] + mp[v][j].second + t[v]);
			}
		} 
		cout<<ans<<"\n";
	} 
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
