#include <bits/stdc++.h>
using namespace std;
int a,b,num;
string s,t;
char cur,cnt;
bool book[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >> t;
	if (a == b)
	{
		cout << "1";
		if (s.substr(0,2) == t.substr(0,2))
		{
			cout << "1";
			cur = s.substr(2,1)[0],cnt = t.substr(2,1)[0],book[cur - 'A' + 1] = book[cnt - 'A' + 1] = true;
			for (int i = 1;i <= 3;i++) num += book[i];
			if (num % 2 == 0)
			{
				cout << "1";
				if (num == 0) cout << "1";
				else if ((book[1] && book[2]) || (book[2] && book[3])) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	cout << "\n";
	return 0;
}
