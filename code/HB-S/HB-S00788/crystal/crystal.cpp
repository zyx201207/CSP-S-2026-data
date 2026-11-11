
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+5;
long long a[N];
int dp[N];
int maxn=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		int cnt=1;
		int q=m;
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]==a[i])
			{
				cnt++;
				continue;
			}
			int c=a[i]-a[j];
			if(q>=c)
			{
				q-=c;
				cnt++;
			}
			else break;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
