#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int p[200005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) 
	{
		cout << a[1];
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i = 2 ; i <= n ; i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m==2)
	{
		long long ans=-1;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i+1 ; j <= n ; j++)
			{
				long long t=a[i]&a[j];
				if(i!=j) ans=max(t,ans);
			}
		}
		cout << ans;
		return 0;
	}
	cout << a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
