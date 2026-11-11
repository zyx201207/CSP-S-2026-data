#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50;
int dp[N],a[N];
int n,m,ans,sum,maxn;
bool ok;
bool cmp(int x,int y)
{
	return  x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		dp[i]=a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]!=a[j])
				{
					maxn=max(maxn,(a[i]&a[j]));
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dp[0]=a[1];
	for(int i=1;i<=5;i++) 
	{
		if(a[i]!=a[i+1]+1)
		{
			ok=1;
			break;
		}
		//cout<<a[i]<<" ";
	}
	if(ok==0)
	{
		cout<<n-m;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k=a[i];
		for(int j=i+1;j<=i+m;j++)
		{
			k=(k&a[j]);
		}
		maxn=max(k,maxn);
	}
	cout<<maxn;
	return 0;
}
