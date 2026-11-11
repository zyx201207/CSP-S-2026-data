#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c)cout<<'1';
	else cout<<'0';
	if(b[1]==d[1])
	{
		if(b[2]==d[2])
		   cout<<'1';
		else cout<<'0';
	}
	else cout<<'0';
	if(b[3]>='A'&&b[3]<='C'||b[3]>='D'&&b[3]<='F')
		if(d[3]>='A'&&d[3]<='C'||d[3]>='D'&&d[3]<='F')
			cout<<'1';
	else cout<<'0';
	if(b[3]+1==d[3])
	{
		if(b[3]=='A'||b[3]=='B')cout<<'1';
		else cout<<'0';
		if(b[3]=='D'&&d[3]=='F')cout<<'1';
		else cout<<'0';
	}		
	return 0;
}