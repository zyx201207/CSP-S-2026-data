#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	bool a,b;
	string c1,s1,c2,s2;
	getline(cin,c1);
	getline(cin,s1);
	getline(cin,c2);
	getline(cin,s2);
	a=(c1==c2);
	b=(s1[2]==s2[2]);
	c=0;
	d=0;
	cout<<a<<b<<c<<d;
	return 0;
}
