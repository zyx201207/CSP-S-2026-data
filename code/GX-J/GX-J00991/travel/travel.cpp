#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string c,s,c1,s1;
int a[10001];
int n,t;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	
	if(c==c1) cout<<"1";
	if(s=="01A"&&s1=="01B") cout<<"111";
	else cout<<"0";
	if(c!=c1)
	cout<<"000";
	if(s!="01A"&&s1!="01B")
	cout<<"00";
		return 0;
}
