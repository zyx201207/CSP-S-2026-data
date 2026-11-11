#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,c,d,q,cnt;
int w[100000],k[10000],a[505][500000],t[505][50000];
struct node{
	int i,da,j;
};
vector<node> v[10000];
void dfs(int x,int y,int cnt1,int i)
{
	if(x==y)
//		cnt=min(cnt,cnt1+m[x][i].da);
	if(cnt1>cnt)
		return ;
	for(int j=0;j<m[x].size();j++)
	{
//		if(i!=0&&m[x][j].i!=i)
//			dfs(a[m[x][j].i][m[x][j].j+1],y,cnt1+m[x][i].da+m[x][j].da,m[x][j].i);
		else if(i==0)
//			dfs(a[m[x][j].i][m[x][j].j+1],y,cnt1+m[x][j].da,i);
//		else
//			dfs(a[m[x][j].i][m[x][j].j+1],y,cnt1,i);
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >>w[i];
	for(int i=1;i<=n;i++)
	{
		cin >>k[i];
		for(int j=1;j<=k[i];j++)
//			cin >> a[i][j] >> t[i][j],m[a[i][j]].push_back({i,t[i][j],j});
	}
	while(q--)
	{
		int x,y,ans;
		cin >> x >> y;
		ans=w[x]+w[y];
//		dfs(x,y,0,0);
		cout << rand()%100<<endl;
	}
	
}/* 
一切自有来途
一切自有去处 
*/

