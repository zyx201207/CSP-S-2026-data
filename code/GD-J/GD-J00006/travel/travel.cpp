#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ge(char s)	{
	return s-'A'+1;
} 
int main()	{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int s1=0,s2=0;
	int s3=0,s4=0;
	for(int i=0;i<a.size();i++)	s1=s1*10+(a[i]-'0');
	for(int i=0;i<c.size();i++)	s2=s2*10+(c[i]-'0');
	if(s1!=s2)	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<b.size()-1;i++)	s3=s3*10+(b[i]-'0');
	for(int i=0;i<d.size()-1;i++)	s4=s4*10+(d[i]-'0');
	if(s3!=s4)	{
		cout<<"1000";
		return 0;
	}
	if(b[2]>='D'&&d[2]>='D'){
		cout<<"1111";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C')	{
		if(abs(ge(b[2])-ge(d[2]))==1)		cout<<"1111";
		else 	cout<<"1110";
		return 0;
	}
	cout<<"1100";
	return 0; 
}
/*
Trick||Treat!
*/
