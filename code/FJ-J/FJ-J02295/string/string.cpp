#include<bits/stdc++.h>
using namespace std;
int a1[200005],a2[200005];
char c1[200005],c2[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	int n,ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a1[i];
		cin >> c1[i];
		a2[n-i+1] = a1[i];
		c2[n-i+1] = c1[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= a1[i]; j++)
		{
			a += c1[i];
		}
	}
	if(a.length()%2==0)
	{
		for(int i = 1; i <= a.length()/2; i++)
		{
			if(a[i] != a[a.length()-i+1])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i = 1; i <= a.length()/2+1; i++)
		{
			if(a[i] != a[a.length()-i+1])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
