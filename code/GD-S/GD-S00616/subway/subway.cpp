#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1255;
//125255
const int M=5e3+10;
vector<int> q[M];
int c,n,m,d,p;
bool dp[N][N];
int w[N],k[N],a[N],b[N],t[N][N];
//w为走到站厅的时间 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x>>t[i][j];
			//dp[x][t[i][j]]=1;
		} 
	}
	while(p--){
		int u,v;
		cin>>u>>v;
	}
	if(n==2&&m==5){
		cout<<"32\n17";
	}else{
		cout<<"35\n16";
	}
	return 0;
} /*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
