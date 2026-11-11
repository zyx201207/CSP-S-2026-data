#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+20;
ll n,m,a[N],cnt;
ll ans=0;
void dfs(int t,int q)
{
	if(t==m-1)
	{
		cnt=a[q];
	}
	for(int i=q;i<=n;i++)
	{
		if(t)
		{
			int b=0;
			b=cnt;
			cnt=cnt & a[i];
			dfs(t-1,i+1);
			cnt=b;
		}
		else
		{
			int b=cnt;
			cnt=cnt & a[i];
			ans=max(ans,cnt);
			cnt=b;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		dfs(m-1,i);
	}
	cout<<ans;
	return 0;
 } 
/*
4 2
3 15 12 12
*/
