#include<bits/stdc++.h>
using namespace std;
string a,c1,b,c2;
int s1,s2,s3,s4;
char k2,k1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c1>>b>>c2;
	int l1=c1.size(),l2=c2.size();
	for(int i=0;i<a.size();i++)
	{
		s1=s1*10+(a[i]-'0');
	}
	for(int i=0;i<b.size();i++)
	{
		s2=s2*10+(b[i]-'0');
	}
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<l1-1;i++)
	{
		s3=s3*10+(c1[i]-'0');
	}
	for(int i=0;i<l2-1;i++)
	{
		s4=s4*10+(c2[i]-'0');
	}
	k1=c1[l1-1],k2=c2[l2-1];
	if(s3!=s4)
	{
		cout<<"1000";
		return 0;
	}
	if((k1>='A'&&k1<='C'&&k2>='D'&&k2<='F')||(k2>='A'&&k2<='C'&&k1>='D'&&k1<='F'))
	{
		cout<<"1100";
		return 0;
	}
	if((k1+'1'==k2+'0')||(k2+'1'==k1+'0'))
	{
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
