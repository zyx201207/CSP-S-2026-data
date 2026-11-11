#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

struct node {int a; char c;};
node s[200010],t[200010];
int ans = 0;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].a >> s[i].c;
		t[n-i+1] = s[i];
	}
//	for (int i = 1;i <= n;i++)
//	{
//		cout << s[i].a << s[i].c << ' ' << t[i].a << t[i].c << endl;
//	}
	int curs = 1,curt = 1;
	while (curs <= n && curt <= n)
	{
		int flag;
		if (s[curs].c != t[curt].c) flag = 1;
		else flag = 0;
		if (s[curs].a > t[curt].a)
		{
//			cout << s[curs].a << s[curs].c << ' ' << t[curt].a << t[curt].c << endl;
//			cout << ans << ' ' << "!!!" << ' ';
			ans += t[curt].a * flag;
//			cout << ans << endl;
			s[curs].a -= t[curt++].a;
			
		}
		else if (s[curs].a < t[curt].a)
		{
//			cout << s[curs].a << s[curs].c << ' ' << t[curt].a << t[curt].c << endl;
//			cout << ans << ' ' << "@@@" << ' ';
			ans += s[curs].a * flag;
//			cout << ans << endl;
			t[curt].a -= s[curs++].a;
		}
		else
		{
//			cout << s[curs].a << s[curs].c << ' ' << t[curt].a << t[curt].c << endl;
//			cout << ans << ' ' << "###" << ' ';
			ans += s[curs++].a * flag;
//			cout << ans << endl;
			curt++;
		}
	}
	cout << ans / 2;
	return 0;
}
