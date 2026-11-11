#include<bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define ll long long
string S;
int const N = 2e5 + 10;
int n;
ll l = 0, r = 0, lp = 0, rp = 0, ans = 0;
pair<int, char> pir[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	rp = n - 1;
	for(int i = 0;i < n;i++)
	{
		cin >> pir[i].FI >> pir[i].SE;
		r += pir[i].FI;
	}
	r -= 1;
	while(l < r && lp < rp)
	{
		ll miner = min(pir[lp].FI, pir[rp].FI);
		if(pir[lp].SE != pir[rp].SE)
		{
			ans += miner;
		}
		l += miner;
		r -= miner;
		pir[lp].FI -= miner;
		pir[rp].FI -= miner;
		if(pir[lp].FI == 0)
			lp++;
		if(pir[rp].FI == 0)
			rp--;
//		cout << l << " " << r << " " << lp << " " << rp << "\n";
	}
	cout << ans;
	
	return 0;
 } 
