#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a,b;
string s1,s2;
int a1[4],b1[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	
	cin>>a>>s1>>b>>s2;
	if(a==01||b==01||a==16||b==16){
		cout<<"0000";
		return 0;
	}
	else if(a==b){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			cout<<1;		
		}
		else cout<<0;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='B')
				cout<<1;
			else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')
				cout<<1;
			else cout<<0;
		}
		else cout<<0;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			if(s1[2]=='A'&&s2[2]=='B') cout<<1;
			else if(s1[2]=='B'&&s2[2]=='A') cout<<1;
			else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
			else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
			else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
			else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else 
	{
		cout<<"0000";
		return 0;	
	}

	
	
	return 0;
 } 
