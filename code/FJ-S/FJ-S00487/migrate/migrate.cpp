#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int inf = 0x3f3f3f3f;
int n; long long d;
long long a[N];
int status[N][N],shortest[N][N];

ifstream fin("migrate.in",ios_base::in);
ofstream fout("migrate.out",ios_base::out);

void solve()
{
	long long ans = 0;
	for(int j = 1; j <= n; j++)
	{
		status[j][j] = 1,shortest[j][j] = 0;
		map<int,int> mp;
		mp[0] = 1;
		int r = j;
		for(int i = j - 1; i >= 1; i--)
		{
			
			while(a[r] - a[i] > d)
			{
				mp[shortest[r][j]] -= status[r][j];
				if(mp[shortest[r][j]] == 0)
					mp.erase(mp.find(shortest[r][j]));
				r--;
			}
			if(mp.empty())
				break;
			shortest[i][j] = mp.begin()->first + 1;
			status[i][j] = mp.begin()->second;
			if(status[i][j] > 3)
				status[i][j] = 3;
			mp[shortest[i][j]] += status[i][j];
			
			if(status[i][j] == 2)
				ans++;
		}
	}
	
	fout << ans << '\n';
	return;
}

void solveA()
{
	fout << max(0LL,n - (d * 2 - 1)) << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(0); fin.tie(0); fout.tie(0);
	int c,t; fin >> c >> t;
	while(t--)
	{
		fin >> n >> d;
		for(int i = 1; i <= n; i++)
			fin >> a[i];	
		if(c == 11 || c == 12)
			solveA();
		else
			solve();
	}
	return 0;
}
