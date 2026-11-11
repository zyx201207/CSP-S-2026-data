#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout)	;
	string a,b,c,d;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	bool pd=true;

	for(int i=0;i<2;i++)
	{
	
		if(a[i]-'0'!=c[i]-'0')
		{
			pd=false ;
			break;
		}
	}
	bool pfd=true;
	for(int i=0;i<2;i++)
	{
		if(b[i]-'0'!=d[i]-'0')
		{
			pfd=false ;
			break;
		}
	}
	if(pd) cout<<"1";
	else cout<<"0";
	bool hg=false;
	if(pd&&pfd)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(pd&&pfd)
	{
		if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
		{
			cout<<"1";
			hg=true;
		}
		else 
		if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
		{
		hg=true;
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"0";
	if(	hg&&pd&&pfd)
	{
		if((b[2]-'a'==d[2]-'a'+1)||(b[2]-'a'+1==d[2]-'a'))
		{	
			cout<<"1";
			return 0;
		}
	}
	cout<<"0";
	return 0;
}
