#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int a, b, c, d, e, f;
bool vis[5];
int z(string x)
{
	int t;
	if(x[0]=='0')
		 t = x[1]-'0';
	else
	{
		t = x[1]-'0';
		t += 10;
	}
	return t;
}
char p(string x)
{
	char t=x[2];
	int v=0;
	v = t-'0';
	return v;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = z(c1);
	b = z(c2);
	c = z(s1);
	d = z(s2);
	e = p(s1);
	f = p(s2);
	if(a==b)
	{
		vis[1] = 1;
		if(c==d)
		{
			vis[2] = 1;
			if(e<=19 && f<=19)
			{
				vis[3] = 1;
				if(e==18 || f==18)
					vis[4] = 1;
			}
			else if(e>19&&f>19)
			{
				vis[3] = 1;
				vis[4] = 1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout << vis[i];
	return 0;
}
