#include <iostream>
using namespace std;
string a,b,c,d;
int main()
{
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c && a!="01" && a!="16") cout<<1;
	else 
	{
	    cout<<"0000";
	    return 0;
	}
	if (b[0]==d[0] && b[1]==d[1]) cout<<1;
	else 
	{
	    cout<<"000";
	    return 0; 
	}
	if (max(b[2],d[2])!='D' || min(b[2],d[2])!='C') 
	{
		cout<<1;
		if (max(b[2],d[2])-min(b[2],d[2])==1) cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
}
