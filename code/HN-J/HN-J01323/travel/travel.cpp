#include<bits/stdc++.h>
using namespace std;
int f[6]={0,0,0,1,1,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1=0,n2=0;
	for(int i=0;i<c1.size();i++)n1=n1*10+c1[i]-'0';
	for(int i=0;i<c2.size();i++)n2=n2*10+c2[i]-'0';
	if(n1==n2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	n1=n2=0;
	for(int i=0;i<2;i++)n1=n1*10+s1[i]-'0';
	for(int i=0;i<2;i++)n2=n2*10+s2[i]-'0';
	if(n1==n2)cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(f[s1[2]-'A']==f[s2[2]-'A'])cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(f[s1[2]-'A']==1)cout<<1;
	else
	{
		if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
	}
	return 0;
}
 
