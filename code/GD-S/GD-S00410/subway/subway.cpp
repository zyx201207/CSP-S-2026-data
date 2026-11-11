#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int w[N];
struct node{
	int a,t;
};
int ans=2e9;
vector<vector<node>>a(N);
vector<bool>vis(N);
int dfs(int x,int y,int now){
	if(x==y)return ans = min(ans,now);
	
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k*2;j++){
			cin >> a[i][j].a >> a[i][j].t; 
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << a[x][y].t << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
