#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxn=-134567867,maxnn=-23456890,sum,mp[2005][2005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	sum=a[1];
	for(int i=2;i<=n;i++)sum&=a[i];
	if(m==1)cout << maxn;
	else if(m==n)cout << sum;
	else if(m==2)
	{
		int maxx=-123456;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[i][j]=a[i]&a[j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;i<=n;i++)
			{
				maxx=max(mp[i][j],maxx);
			}
		}
		cout << maxx;
	}
	else cout << 1;
	return 0;
} 
