#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e7 + 9;
int n;
char c[N];
int cnt = 0;

int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		int a;
		char t;
		cin >> a >> t;
		for(int j=1;j<=a;j++)
		{
			c[++cnt] = t;
		}
	}
	int i=1, j=cnt;
	ll ans = 0;
	while(i <= j)
	{
		if(c[i] != c[j]) ans++;
		i++,j--;
	}
	cout << ans;
	
	return 0;
}
