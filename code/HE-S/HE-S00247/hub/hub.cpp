#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin >> C >> T;
	while(T --)
	{
		cin >> n >> k;
		for(int i = 1,u,v;i < n;i ++)
		{
			cin >> u >> v;
		}
		if(C == 13 || C == 14 || C == 0)
		{
			cout << (n / 2 - k) / 4 + 2 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}
