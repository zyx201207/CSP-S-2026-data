#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	string a,b,c,d; cin>>a>>b>>c>>d;
	int a1,a2,a3,a4;
	if(a!=c) a1=a2=a3=a4=0;
	else a1=1;
	
	string tmp1=b.substr(0,2),tmp2=d.substr(0,2);
	if(tmp1!=tmp2) a2=a3=a4=0;
	else if(a1==1) a2=1;
	
	if(b[2]=='A' and a2==1)
	{
		if(d[2]!='B' and d[2]!='C') a3=a4=0;
		else a3=1;
	}
	else if(b[2]=='B' and a2==1)
	{
		if(d[2]!='A' and d[2]!='C') a3=a4=0;
		else a3=1;
	}
	else if(b[2]=='C' and a2==1)
	{
		if(d[2]!='A' and d[2]!='B') a3=a4=0;
		else a3=1;
	}	
	else if(b[2]=='D' and a2==1)
	{
		if(d[2]!='F') a3=a4=0;
		else a3=1;
	}
	else if(b[2]=='F' and a2==1)
	{
		if(d[2]!='D') a3=a4=0;
		else a3=1;
	}
	
	if(b[2]=='A' and a3==1)
	{
		if(d[2]=='B') a4=1;
		else a4=0;
	}
	else if(b[2]=='B' and a3==1)
	{
		if(d[2]=='A' or d[2]=='C') a4=1;
		else a4=0;
	}
	else if(b[2]=='C' and a3==1)
	{
		if(d[2]=='B') a4=1;
		else a4=0;
	}
	else if(b[2]=='D' and a3==1)
	{
		if(d[2]=='F') a4=1;
		else a4=0;
	}
	else if(b[2]=='F' and a3==1)
	{
		if(d[2]=='D') a4=1;
		else a4=0;
	}
	
	cout<<a1<<a2<<a3<<a4;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
