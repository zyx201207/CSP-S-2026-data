#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int N=1e +5;
//int a[N];
string s1,s2,s3,s4;
int a;
signed main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if((s1[1]==s3[1])&&(s1[0]==s3[0] ))
	{
		cout<<1;
		a=1;
	}
	else
	{
		cout<<0;
		a=0;
	}
	
	if(s2[1]==s4[1]&&a==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		a=0;
	}
	if(s2[2]<=67&&s4[2]<=67&&a==1)
	{
		cout<<1;
	}
	else if( (s2[2]=='D'||s4[2]=='F')&&(s2[2]=='D'||s4[2]=='F')&&a==1)
	{
		cout<<1;
		a=2;
	}
	else{
		cout<<0;
		a=0;
	};
	
	if(a==2) cout<<1;
	else if(a==1)
	{
		if(s2[2]=='B'||s4[2]=='B') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	
	
	return 0;
 } 
