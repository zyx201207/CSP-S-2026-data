#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
int a[MAXN],tmp[MAXN],b[MAXN];
long long n,m,sum,cnt;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
    cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		tmp[i] = a[i];
	}
	for(int j = 1;j < n;j++)
    {
    	sum = 0;
		for(int i = j;i < n;i++)
		{
			sort(a+1,a+n+1);
			for(int u = i+1;u <= n;u++)
			{
				
				if(a[u] > a[i])
				{
					if(sum + a[u]-a[i] > m) break;
					sum += a[u]-a[i];
					a[i] = a[u];
					break;
				}
			}
			
		}
		for(int k = 1;k <= n;k++)
		{
			if(a[k] != tmp[k]&& (a[k] == a[k-1] || a[k] == a[k+1])) cnt++;
			if(k == n) b[j] = cnt;
		}
	}
	int maxn = -10000;
    for(int i = 1;i < n;i++)
    {
    	maxn = max(b[i],maxn);
	}
	cout << maxn;
	return 0;
}
