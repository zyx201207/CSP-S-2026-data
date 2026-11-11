#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int aa,bb;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	if(b[2]=='A')aa=1;
	else if(b[2]=='B')aa=2;
	else if(b[2]=='C')aa=3;
	else if(b[2]=='D')aa=4;
	else aa=5;
	if(d[2]=='A')bb=1;
	else if(d[2]=='B')bb=2;
	else if(d[2]=='C')bb=3;
	else if(d[2]=='D')bb=4;
	else bb=5;
	
	if(a==c)cout<<1;
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')))
	{
		cout<<1;
	}
	else cout<<0;
	
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&abs(aa-bb)==1)
	{
		cout<<1<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
