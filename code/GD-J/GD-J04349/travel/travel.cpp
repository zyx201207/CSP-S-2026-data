#include<bits/stdc++.h>
using namespace std;
bool cc(char a,char b)
{
	if(a<='C'&&b<='C') return 0;
	if(a>'C'&&b>'C') return 0;
	return 1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000\n";
	else if(b[0]!=d[0]||b[1]!=d[1]) cout<<"1000\n";
	else if(cc(b[2],d[2])) cout<<"1100\n";
	else if(abs(b[2]-d[2])!=1) cout<<"1110\n";
	else cout<<"1111\n";
	return 0;
}
