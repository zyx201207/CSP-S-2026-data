#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double
#define endl "\n"
const int N=2e5+10;
int n,m,a[N],ans;
bool xxx(int a,int b)
{
	return a>b;
}
bool tcf(int abab)
{
	for(int i=1;i<=abab;i++)
	{
		if(log2(a[i])%1==0)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(i==1)
		{
			ans=a[i]; 
		}
		maxn=max(maxn,a[i]);
		ans=ans&a[i];
	}
	sort(a+1,a+n+1,xxx);
	if(m==1)
	{
		cout << maxn;
		return 0;
	}
	if(m==n)
	{
		cout << ans;
		return 0;
	}
	if(m==2)
	{
		int maxnn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxnn=max(maxnn,a[i]&a[j]);
			}
		}
		cout << maxnn;
		return 0;
	}
	if(m==n-1)
	{
		int maxnnn=0;
		for(int i=1;i<=n;i++)
		{
			maxnnn=max(maxnnn,ans&(~a[i]));
		}
		cout << maxnnn ;
		return 0;
	}
	if(log2(a[i]+1)%1==0)
	{
		cout << a[m];
	}
	if(tcf(n))
	{
		cout << a[m];
	}
	
	return 0;
}
