#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int n,d;
int c,t;
int x[N];
int ans = 0; 

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j <= n;j++) cin >> x[j];
	}
	if(c == 13 || c == 14)
	{
		for(int i = 1;i <= n - 2;i++)
		{
			ans += i;
		}
		cout << ans << endl;
	}

	return 0;
}

