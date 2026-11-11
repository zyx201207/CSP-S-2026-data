#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cc,c;
	int ss,s;
	int e=0,f=0,g=0,h=0;
	cin >> c;
	cin >> s ;
	cin >> cc ;
	cin >> ss;
	if(c!=cc)
	{
		e=1;
		if(s-ss<=4||ss-s<=4)
		{
			f=1;
		}
		if(s-ss<=2||ss-s<=2)
		{
			g=1;
		}
		if(s-1==ss||s+1==ss||ss-1==s||ss+1==s)
		{
			h=1;
		}
	}
	cout << e << f << g << h ;
	return 0;
}
