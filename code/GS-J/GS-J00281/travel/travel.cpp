#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	bool che=false,pai=false,ce=false,lin=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) che=true;
	if(che && s1[0]==s2[0] && s1[1]==s2[1]) pai=true;
	if(che && pai && s1[2]>='A' && s1[2]<='C' && s2[2]>='A'&& s2[2]<='C' || s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F' ) ce=true;
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2] && che && pai && ce ) lin=true;
	if(che) cout<<1;
	else cout<<0;
	if(pai)
		cout<<1;
	else cout<<0;
	if(ce) cout<<1;
	else cout<<0;
	if(lin) cout<<1;
	else if(lin==0) cout<<0;
	return 0;
}

