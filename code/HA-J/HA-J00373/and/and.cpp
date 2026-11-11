#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef pair<int,int> PII;
const int N=2e5+5;
int n,m;
int a[N];
bool vis[N];
int ans,sum;
void dfs(int len)
{
	int cnt=0,sum=0;
	if(len==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				cnt++;
				if(cnt==1) sum=a[i];
				else sum&=a[i];
			}
		}
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(len+1);
			vis[i]=false;
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n>20)
	{
		cout<<a[n];
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
