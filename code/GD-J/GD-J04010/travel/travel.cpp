#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int lb,ld,ok=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c&&a!="01"&&a!="16"&&c!="01"&&c!="16")
	{
		cout<<1;
	}
	else if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(b[i]!=d[i])
		{
			ok=1;
			cout<<0;
			break;
		}
	}
	if(ok==0) cout<<1;
	lb=int(b[2]);
	ld=int(d[2]);
	if(abs(lb-ld)==1&&lb!=67&&ld!=68&&ok==0)
	{
		cout<<11;	
	}
	else if(abs(lb-ld)==1&&lb!=67&&ld!=68&&ok==1)
	{
		cout<<10;	
	}
	else if(abs(lb-ld)==1&&lb==67&&ld==68)
	{
		cout<<"00";	
	}
	else if(abs(lb-ld)!=1&&abs(lb-ld)==2&&(lb==65&&ld==67)||lb==67&&ld==65)
	{
		cout<<10;	
	}
	else if(abs(lb-ld)!=1&&abs(lb-ld)==2&&lb!=65&&ld!=67)
	{
		cout<<"00";	
	}
	else
	{
		cout<<"00";
	}
	return 0;
} 
