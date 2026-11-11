#include<bits/stdc++.h>
#define int long long
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n' 
using namespace std;
using pii=pair<int,int>;
int n,m;
int a[210010];
int mx=-TNF;
bool st[210010];
void dfs(int x,int cnt)
{
	if(x==m)
	{
		//cout<<cnt<<endl;
		mx=max(cnt,mx);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==1)continue;
		st[i]=1;
		int u=cnt&a[i];
		dfs(x+1,u);
		st[i]=0;
	}
}
void d()
{
	cin>>n>>m;
	int r=0 ;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)r=1;
	}
	for(int i=1;i<=n;i++)
	{
		st[i]=1;
		dfs(1,a[i]);
		st[i]=0;
	}
	cout<<mx<<endl;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t; 
	while(t--)d();
}
/*4 2
3 15 12 12
5 3
31 3 1 15 7
0 0 0 0 1
0 0 0 1 0
0 0 0 1 1 3
0 0 1 0 0
0 0 1 0 1
0 0 1 1 0
0 0 1 1 1 7
0 1 0 0 0
0 1 0 0 1
0 1 0 1 0
0 1 1 0 0
0 1 1 0 1
0 1 1 1 0
0 1 1 1 1 15
*/
