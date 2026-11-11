#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e="   ",f="   ",m="   ",n="   ",z="01",s="16";
	cin>>a>>b>>c>>d;
	if(a==z||a==s||c==z||==s)
	{
		return 0;
	}
	if(a==c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<3;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			e[i]=b[i];
		}
		else
		{
			m[i]=b[i];
		}
		if(d[i]>='0'&&d[i]<='9')
		{
			f[i]=d[i];
		}
		else
		{
			n[i]=d[i];
		}
	}
	if(e==f)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((m[2]!='F'&&m[2]!='D')&&(n[2]!='D'&&n[2]!='F')||(e==f&&m[2]=='F'||m[2]=='D'&&n[2]=='D'&&n[2]=='F'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((e==f&&m[2]=='F'||m[2]=='D'&&n[2]=='D'&&n[2]=='F')||(m[2]!='A'||m[2]!='C')&&(n[2]!='A'||n[2]!='C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
