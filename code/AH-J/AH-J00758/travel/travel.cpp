#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p(char ch)
{
	if(ch=='A'||ch=='B'||ch=='C')return 1;
	return 0;
}
int f(char ch)
{
	if(ch=='A')return 1;
	if(ch=='B')return 2;
	if(ch=='C')return 3;
	if(ch=='D')return 5;
	if(ch=='F')return 6;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
	char cc1=s1[2],cc2=s2[2];
	if(c1==c2&&ss1==ss2)
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&ss1==ss2&&(p(cc1)==p(cc2)))
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&ss1==ss2&&(p(cc1)==p(cc2))&&(abs(f(cc1)-f(cc2))==1))
		cout<<1<<'\n';
	else
		cout<<0<<'\n';
	return 0;
}
