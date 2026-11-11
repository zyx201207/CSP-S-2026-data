#include <bits/stdc++.h>
using namespace std;

long long a[500005];
long long p[500005];
long long q[500005];

map <int,int> mp;
map <int,int> mp2;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin >> n >> m;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	long long cur = 0;
	for(long long i = 1;i <= n;i++)
	{
		for(long long j = i;j <= n;j++)
		{
			if(mp[a[j]] != 0) 
			{
				for(long long k = 1;k <= m;k++) mp[k] = 0;
			}
			mp[a[j]]++;
		} 
		for(long long k = 1;k <= m;k++) mp2[k] += mp[k];
		for(long long k = 1;k <= m;k++) mp[k] = 0;
	}
	for(long long i = 1;i <= m;i++)
	{
		cout << mp2[i] << " ";
	}
	return 0;
}
