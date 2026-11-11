#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans1,ans2,ans3,ans4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    ans1 = (a == c);
    ans2 = (b[0] == d[0] && b[1] == d[1]) * ans1;
    if(ans2 == 1)
    {
		if((b[2] == 'D' || b[2] == 'E') && (d[2] == 'D' || d[2] == 'E')) ans3 = ans4 = 1;
		if((b[2] != 'D' && b[2] != 'E') && (d[2] != 'D' && d[2] != 'E'))
		{
			ans3 = 1;
			if(b[2] == 'B' || d[2] == 'B') ans4 = 1;
		}
	}
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
