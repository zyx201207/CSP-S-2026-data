#include <bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
bool c1()
{
	char n,m;
	n=a[2];
	m=b[2];
	return n>='A'&&n<='C'&&m>='A'&&m<='C'||n>='D'&&n<='F'&&m>='D'&&m<='F';
}
bool c2()
{
	char n,m;
	n=max(a[2],b[2]);
	m=min(a[2],b[2]);
	if(n-m==1&&n<='C')return 1;
	if(n-m==2&&m=='D')return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y)cout<<1;
	else {
	cout<<"0000";return 0;}
	if(a[0]==b[0]&&b[1]==a[1])cout<<1;
	else {
	cout<<"000";return 0;}
	if(c1())cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	cout<<(c2());
	return 0;
}