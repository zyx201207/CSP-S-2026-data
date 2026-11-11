#include <bits/stdc++.h>
using namespace std;
bool samepi(string a,string b)
{
	if(a[0]==b[0]&&a[1]==b[1])return 1;
	return 0;
}
bool gett(string a)
{
	if('A'<=a[2]&&a[2]<='C')return 0;
	return 1;
}
bool samece(string a,string b)
{
	return gett(a)==gett(b);
}
bool xl(string a,string b)
{
	if(a[2]>b[2]) return xl(b,a);
	if(a[2]<'C'&&b[2]-a[2]==1) return 1;
	if(a[2]=='D'&&b[2]=='F')return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool samec=0;
	bool samep=0;
	if(c1==c2)
	{
		samec=1;
		cout<<1;
	}
	else cout<<0;
	if(samec&&samepi(s1,s2))
	{
		samep=1;
		cout<<1;
	}
	else cout<<0;
	if(samec&&samep&&samece(s1,s2))
	{
		cout<<1;
	}
	else cout<<0;
	if(samec&&samep&&xl(s1,s2)) cout<<1;
	else cout<<0;
	return 0;
}
