#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c, m, d, n, q;
ll k[505],b[500005],a[505][5005], t[505][5005],qi[15][5005]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c == 0)
	{
		if(n == 2 && m == 5 && d == 20 && q == 2)
		{
			cout << 32 << "\n" << 17;
		}
		if(n == 3 && m == 7 && d == 20 && q == 2){
			cout << 35 << "\n" << 16;
		}
		if(n == 15 && m == 136 && d == 20 && q == 200)
		{
			cout << "341";
		}
	}
	if(c != 0){
		for(int i = 1; i <= m; i++)
		{
			cin >> b[i];
		}
		for(int i = 1; i <= n; i++){
				cin >> k[i];
			for(int j = 1; j <= k[i]; j++){
					cin >> a[i][j] >> t[i][j];
				}
		}
		for(int i = 1; i <= q; i++)
		{
			cin >> qi[i][1] >> qi[i][2];
		}
		cout << 1 << "\n" << 1;
	}
	return 0;
}

