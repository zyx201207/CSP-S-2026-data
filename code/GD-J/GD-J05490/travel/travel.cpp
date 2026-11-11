#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
//constexpr int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	char b2 = b[2], d2 = d[2];
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0; //was initialized as -1, but changed to avoid mistakes
	if(a != c)
	{
		ans1 = 0; ans2 = 0; ans3 = 0; ans4 = 0;
	}
	else
	{
		ans1 = 1;
		if((b[0] != d[0]) || (b[1] != d[1]))
		{
			ans2 = 0; ans3 = 0; ans4 = 0; 
		}
		else
		{
			ans2 = 1;
			if(!(((b2 - 'A' <= 2) && (d2 - 'A' <= 2)) || ((b2 - 'A' >= 3) && (d2 - 'A' >= 3))))
			{
				ans3 = 0; ans4 = 0;
			}
			else
			{
				ans3 = 1;
				if(abs(b2 - d2) != 1) ans4 = 0;
				else ans4 = 1;
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	//cout << '\n' << "²»Òª×¢ÊÍfreopen; rp++." << '\n';
	//froepen("travle.in", "w", stdin);
	return 0;
}
//a pretty easy and ordinary T1
