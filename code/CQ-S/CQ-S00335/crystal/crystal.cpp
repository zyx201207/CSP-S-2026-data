#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],w[500005],maxn = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(m > 1000000001){
		for(int i = 1;i;i++)
		{
			maxn+=i;
			if(maxn > m)
			{
				maxn = i-1;
				break;
			}
			else if(i > n)
			{
				cout << i-1;
				return 0;
			}
		}
		cout << maxn;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}//500000
	sort(a+1,a+n+1); 
	for(int i = 1;i < n;i++)
	{
		w[i] = a[i+1] - a[i];
	}//10^6
	for(int i = 2;i <= n;i++)//5*10^5
	{
		int sum = 0,ans = 0,d = 0;
		for(int j = i-1;sum < m && j > 0;j--)//25*10^10
		{
			ans++;
			d += w[j];
			sum += d;
		}
		if(sum == m)ans++;
		if(maxn < ans)
		{
			maxn = ans;
			cout << i;
		}
	}
	cout << maxn;
	return 0;
 } 
/*

*/
