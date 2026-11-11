#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
//  check the freopen
int n,m,cnt[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	if (m == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0;i < n;i++)
	{
		int s;
		cin >> s;
		cnt[s]++;
	}
	for (int i = 1;i <= m;i++)
	{
		cout << cnt[m] << " ";
	}
	
	return 0;
}
