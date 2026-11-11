#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	string lina = ""+b[0]+b[1];
	string linb = ""+d[0]+d[1];
	char aa = b[2],bb = d[2];
	if(a != c)
	{
		cout<<"0000";
	}
	else if(lina != linb)
	{
		cout<<"1000";
	}
	else if((aa>='D' && bb <= 'C') || (aa<='C' && bb >='D'))
	{
		cout<<"1100";
	}
	else if(aa == bb+1 || bb == aa+1)
	{
		cout<<"1111";
	}
	else
	{
		cout<<"1110";
	}
	return 0;
}
