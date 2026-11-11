#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0;
	char t1,t2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	t1=s1[2];
	t2=s2[2];
	if (c1 == c2)
	{
		a=1;
	}
	if ((c1 == c2) && ((s1[0] == s2[0]) && (s1[1] == s2[1])))
	{
		b=1;
	}
	if ((c1 == c2) && ((s1[0] == s2[0]) && (s1[1] == s2[1])) && ((t1 == 'F' && t2 == 'D') || (t1 == 'D' && t2 == 'F') || (t1 == 'A' && t2 == 'C') || (t1 == 'C' && t2 == 'A') || (t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'A') || (t1 == 'B' && t2 == 'C') || (t1 == 'C' && t2 == 'B')))
	{
		c=1;
	}
	if ((c1 == c2) && ((s1[0] == s2[0]) && (s1[1] == s2[1])) && ((t1 == 'F' && t2 == 'D') || (t1 == 'D' && t2 == 'F') || (t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'A') || (t1 == 'B' && t2 == 'C') || (t1 == 'C' && t2 == 'B')))
	{
		d=1;
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
