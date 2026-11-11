#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1])
	{
		cout<<1000<<endl;
		return 0;
	}
//	cout<<tmp1<<" "<<tmp2<<endl;
//	if(tmp1!=tmp2)	cout<<1000<<endl,exit(0);
//	
	int c=0,d=0;
	
	if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C')) 
	{
		c=1;
		if(abs(s1[2]-s2[2])==1)	d=1; 
	}
	if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F'))
	{
		cout<<1111<<endl;
	}
	cout<<11<<c<<d<<endl;
	return 0;
} 
