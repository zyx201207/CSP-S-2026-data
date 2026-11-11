#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	int n1=0;
	int n2=0;
	int n3=0;
	int n4=0;
	string t={'A','B','C','D','F'};
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			n1=0;
			break;
		}
		n1=1;
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			n2=0;
			break;
		}
		n2=1;
	}
	if(s1[2]==t[0])
	{
		if(s2[2]==t[1])
			n3=1,n4=1;
		if(s2[2]==t[2])
			n3=1;
	}
	if(s1[2]==t[1])
	{
		if(s2[2]==t[1]||s2[2]==t[0])
			n3=1,n4=1;
	}
	if(s1[2]==t[2])
	{
		if(s2[2]==t[1])
			n3=1,n4=1;
		if(s2[2]==t[0])
			n3=1;
	}if(s1[2]==t[3])
	{
		if(s2[2]==t[4])
			n3=1,n4=1;
	}
	if(s1[2]==t[4])
	{
		if(s2[2]==t[3])
			n3=1,n4=1;
	}
	if(n1==0)
		n2=0,n3=0,n4=0;
	if(n2==0)
		n3=0,n4=0;
	cout<<n1<<n2<<n3<<n4;
}
