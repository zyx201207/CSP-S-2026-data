#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
//  check the freopen
long long a[200005],ans = 0;
char c[200005];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int j=1;
	for (int i = 1;i <= n;i++,j++)
	{
		
		if (c[j]!=c[n+1-i])
		{
			ans+=min(a[j],a[n+1-i]);
		}
		if (a[j]>a[i+n-1])
		{
			a[j]-=a[i+n-1];
			j--;
			a[i+n-1] = 0;
			c[n+1-i]=c[j];
		}
		else if (a[j]==a[i+n-1])
		{
			a[j] = 0;
			a[i+n-1] = 0;
		}
		else
		{
			a[i+n-1]-=a[j];
			a[j] = 0;
			c[j]=c[n+1-i];
		}
	}
	cout << ans;
	
	return 0;
}
