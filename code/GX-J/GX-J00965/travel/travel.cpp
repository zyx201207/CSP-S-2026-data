#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
using namespace std;
struct dd
{
	int n,id;
	char k;
}a,b;
char near1[3]={'A','B','C'};
bool near(char x,char y)
{
	if((x<='C' && y>='D') || (y<='C' && x>='D'))
		return 0;
	if(x<='C')
	{
		if(x+1 == y || y+1 == x)
			return 1;
		else
			return 0;
	}
	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.n>>a.id>>a.k;
	cin>>b.n>>b.id>>b.k;
	if(a.n!=b.n)	{cout<<"0000";return 0;}
	else  	cout<<"1";
	if(a.id!=b.id)	{cout<<"000";return 0;}
	else 	cout<<"1";
	if((a.k=='A' || a.k=='B' || a.k=='C') && (b.k=='A' || b.k=='B' || b.k=='C'))
		cout<<"1";
	else
	if((a.k=='D' || a.k=='F') && (b.k=='D' || b.k=='F'))
		cout<<"1";
	else 	{cout<<"00";return 0;}
	if(near(a.k,b.k))
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
