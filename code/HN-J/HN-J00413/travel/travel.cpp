#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int k = 1,a=0,b=0;
	for(int i = c1.length()-1;i>=0;i--)
	{
		a+=(c1[i]-'0')*k;
		b+=(c2[i]-'0')*k;
		k*=10;
	}
	if(a==b)
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int p = (s1[0]-'0')+(s1[1]-'0')*10;
	int q = (s2[0]-'0')+(s2[1]-'0')*10;
	if(p==q)
	{
		cout << 1;
	}
	else
	{
		cout << "000";
		return 0;
	}
	int x,y;
	x = s1[s1.length()-1]-'D';
	y = s2[s2.length()-1]-'D';
	if(x*y>0)
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	bool l = 1;
	if((s1[s1.length()-1]-'D'==0)&&(s2[s2.length()-1]-'C'==0))
	{
		l=0;
	}
	if((s1[s1.length()-1]-'C'==0)&&(s2[s2.length()-1]-'D'==0))
	{
		l=0;
	}
	if((x-y==1||y-x==1)&&l)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
