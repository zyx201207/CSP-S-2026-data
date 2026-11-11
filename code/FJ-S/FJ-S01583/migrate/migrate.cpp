#include<bits/stdc++.h>
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define int long long
using namespace std;
using pii=pair<int,int>;
int n,d;
int a[2000100];
int mx=TNF;
map<int,int>mp;
void dfs(int x,int y,int cnt,int cs)
{
	if(x==y)
	{
		mp[cs]++; 
		mx=min(mx,cs);
		return ;
	}
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[x]>d)break;
		dfs(i,y,cnt+a[i]-a[x],cs+1);
	}
}
void ddd()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int r=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)	mp[i]=0;
			mx=TNF;
			dfs(i,j,0,0);
			if(mp[mx]==2)
			{
				cnt++; 
			}
		}
	}
	cout<<cnt<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int qqwe;
	cin>>qqwe;
	int t=1;
	cin>>t;
	while(t--)ddd();
}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
 6 4
 2 4 6 8 10 12
*/

