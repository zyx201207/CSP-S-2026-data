#include <bits/stdc++.h>
using namespace std;
bool f[256];
void solve()
{
	string a,b,a1,b1;
	char c,c1;
	string s,s1;
	cin >> a >> s >> a1 >> s1;
	b = s[0]+s[1];
	b1 = s1[0]+s1[1];
	c = s[2];
	c1 = s1[2];
	f['A'] = f['B'] = f['C'] = 1;
	if(a == a1)
	{
		cout << 1;
		if(b == b1)
		{
			cout << 1;
			if(f[c] == f[c1])
			{
				cout << 1;
				if(c+1 == c1 || c1+1 == c){
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	solve();
	return 0;
}
