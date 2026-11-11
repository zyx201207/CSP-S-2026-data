#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char check[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	int k1,k2;
	for(int i=0;i<=1;i++)
	{
		k1=k1*10+(c1[i]-'0');
		k2=k2*10+(c2[i]-'0');
	}
	for(int i=1;i<=4;i++) check[i]='0';
	if(k1==k2) check[1]='1';
	else
	{
		for(int i=1;i<=4;i++) cout<<check[i];
		cout<<"\n";
		return 0;
	}
	
	int r1,r2;
	for(int i=0;i<=1;i++)
	{
		r1=r1*10+(s1[i]-'0');
		r2=r2*10+(s2[i]-'0');
	}
	if(r1==r2) check[2]='1';
	else
	{
		for(int i=1;i<=4;i++) cout<<check[i];
		cout<<"\n";
		return 0;
	}
	
	char si1,si2;
	si1=s1[2],si2=s2[2];
	if(r1==r2&&si1==si2||si1>='A'&&si1<='C'&&si2>='A'&&si2<='C'||si1>='D'&&si1<='F'&&si2>='D'&&si2<='F')
		check[3]='1';
	else
	{
		for(int i=1;i<=4;i++) cout<<check[i];
		cout<<"\n";
		return 0;
	}
	
	if(check[3]=='1')
	{
		if(si1>='A'&&si1<'C')
			if(si1-1==si2||si1+1==si2) check[4]='1';
		else if(si1=='C') 
			if(si1-1==si2) check[4]='1';
		else if(si1=='D'&&si2=='F'||si2=='D'&&si1=='F') check[4]='1';
	}
	else
	{
		for(int i=1;i<=4;i++) cout<<check[i];
		cout<<"\n";
		return 0;
	}
	
	for(int i=1;i<=4;i++) cout<<check[i];
	cout<<"\n";
	return 0;	
} 
