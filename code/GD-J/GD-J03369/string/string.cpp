#include <iostream>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	//ll len = 0;
	vector<pair<int, char>> g(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		char c;
		cin >> a >> c;
		
		//len += a;
		g[i] = {a, c};
	}
	
	//cout << "h" << endl;
	ll ans = 0; //1 为g的下标，2为该字母的计数 
	int l1 = 0, l2 = 1, r1 = g.size() - 1, r2 = g[r1].first;
	
	while (l1 <= r1)
	{	
		//cout << "l1: " << l1 << " l2: " << l2 << " r1: " << r1 << " r2: " << r2 << endl;
		
		if (l1 == r1)
		{
			if (!(l2 < r2))
			{
				break;
			}
		}
		
		if (l1 < r1) //直接跳过 
		{
			ll jd = min(g[l1].first - l2 + 1, r2);
			if (g[l1].second != g[r1].second)
			{
				ans += jd;
			}
			
			if (l2 + jd <= g[l1].first)
			{
				l2 += jd;
			}
			else
			{
				l1++;
				l2 = 1;
			}
			
			if (r2 - jd >= 1)
			{
				r2 = r2 - jd;
			}
			else
			{
				r1--;
				r2 = g[r1].first;
			} 
			
			/*l1++;
			l2 = 1;
			
			r1--;
			r2 = g[r1].first;*/
			//cout << 't' << ans << endl << endl; 
			
			continue;
		}
		
		if (g[l1].second != g[r1].second)
		{
			ans++;
		}
		
		if (l2 + 1 <= g[l1].first)
		{
			l2++;
		}
		else
		{
			l1++;
			l2 = 1;
		}
		
		if (r2 > 1)
		{
			r2--;
		}
		else
		{
			r1--;
			r2 = g[r1].first;
		} //到底了就下标-1 
		
		//cout << ans << endl << endl; 
	}
	
	cout << ans;
	return 0;
}
