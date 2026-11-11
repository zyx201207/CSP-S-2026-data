#include <bits/stdc++.h> 
using namespace std;
int a, g, d;
char h;
int s[200005][2];
int sm = 1, dm;//扫描标记 
int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin >> a;
	dm = a;
	for(int f = 1; f <= a; f++)
	{
		cin >> g >> h;
		s[f][1] = g;//团块数 
		s[f][2] = int(h);//团块种类 
	}
	while(sm <= a / 2 && dm >= a / 2)
	{
		if(s[sm][2] != s[dm][2])
		{
			if(s[sm][1] >= s[dm][1])
			{
				d += s[dm][1];
				s[sm][1] -= s[dm][1];
				dm--;
			}
			else
			{
				d += s[sm][1];
				s[dm][1] -= s[sm][1];
				sm++;
			}
			if(s[sm][1] == 0)
				sm++;
		}
		else
		{
			if(s[sm][1] >= s[dm][1])
			{
				s[sm][1] -= s[dm][1];
				dm--;
			}
			else
			{
				s[dm][1] -= s[sm][1];
				sm++;
			}
			if(s[sm][1] == 0)
				sm++;
		}
	}
	cout << d;
	return 0;
}
