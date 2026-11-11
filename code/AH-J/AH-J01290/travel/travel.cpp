#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char ed1=b[2],ed2=d[2];
	int c1=0,c2=0;
	int c3,c4;
	for(int i=0;i<a.size();i++)
	{
		c1=c1*10+(a[i]-'0');
		c2=c2*10+(c[i]-'0');
	}
	for(int i=0;i<2;i++)
	{
		c3=c3*10+(b[i]-'0');
		c4=c4*10+(d[i]-'0');
	} 
	if(c1!=c2)cout<<"0000";
	else 
	{
		if(c3!=c4)cout<<"1000";
		else
		{
			int a1=0,a2=0;
			if(ed1=='A'||ed1=='B'||ed1=='C')a1=1;
			else a1=2;
			if(ed2=='A'||ed2=='B'||ed2=='C')a2=1;
			else a2=2;
			if(a1!=a2)cout<<"1100";
			else
			{
				if((ed1=='A'&&ed2=='C')||(ed1=='C'&&ed2=='A'))cout<<"1110";
				else cout<<"1111";
			}
		}
	} 
	return 0;
} 
