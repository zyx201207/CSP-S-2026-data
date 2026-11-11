#include<bits/stdc++.h>
using namespace std;
string a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1; i <= 4;i++)
	{
		cin >> a[i];
	}
	if(a[1] == a[3])
	{
		cout << 1;
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int s1 , s2;
	s1 = a[2][0]*10+a[2][1];
	s2 = a[4][0]*10+a[4][1];
	if(s1 == s2)
	{
		cout << 1; 
	}
	else
	{
		cout <<"000";
		return 0;
	}
	int p1 , p2;
	p1 = a[2][2]-'A';
	p2 = a[4][2]-'A';
	if(p1<=2&&p2<=2||p1==3&&p2==5||p2==3&&p1==5)
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(abs(p2-p1) == 1&&p2!=3&&p1!=3||p1 == 3&&p2 == 5||p1 == 5&&p2 == 3)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
