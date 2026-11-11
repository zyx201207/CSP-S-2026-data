#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	bool flag = true;
	if(a == b) cout<<1;
	else
	{
		cout<<0;
		flag = false;
	}
	string x,y;
	for(int i = 0;i < 2;i++)
	{
		x += c[i];
		y += d[i];
	}
	if(x == y && flag != false) cout<<1;
	else
	{
		cout<<0;
		flag = false;
	}
	if(c[2] >= 'A' && c[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' && flag != false) cout<<1;
	else if(c[2] == 'D' || c[2] == 'E' && d[2] == 'D' || d[2] == 'E' && flag != false) cout<<1;
	else
	{
		cout<<0;
		flag = false;
	}
	if(c[2]-d[2] == 1 || d[2]-c[2] == 1)
	{
		if(c[2] == 'C' && d[2] == 'D' || c[2] == 'D' && d[2] == 'C') cout<<0;
		else if(flag != false) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
