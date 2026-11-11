#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int l,m;
string print()
{
	if(a!=x)
		return "0000";
	if(b[0]!=y[0]||b[1]!=y[1])
		return "1000";
	if(l!=m)
		return "1100";
	if(l==1&&b[2]!='B'&&y[2]!='B')
		return "1110";
	return "1111";
}
int side(string n)
{
	if(n[2]=='D'||n[2]=='F')
		return 2;
	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	l=side(b);
	m=side(y);
	cout<<print();
	return 0;
}
