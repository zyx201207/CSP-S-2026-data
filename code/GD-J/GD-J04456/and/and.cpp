#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,a[N],m,ans=2147483648,maxx=0;
void prin()
{
	maxx=max(maxx,ans);
}
void dfs(int x)
{
	if(x>m)
	{
		prin();
		ans=2147483648;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		ans&=a[i];
		dfs(x+1);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	dfs(1);
	
	cout<<maxx;
	return 0;
}

/*
4 2
3 15 12 12
*/
