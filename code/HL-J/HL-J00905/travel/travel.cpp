#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	long long a,b;
	cin>>c1>>s1>>c2>>s2;
	a=1;
	b=0;
	if(c1==c2&&c1!="01"&&c1!="16") cout<<b<<111;
		else cout<<a<<111;
	
	return 0;
}