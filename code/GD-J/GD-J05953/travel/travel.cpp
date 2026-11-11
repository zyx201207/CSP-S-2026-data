#include<bits/stdc++.h>
using namespace std;
string s,st;
string s1,st1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>st;
	cin>>s1>>st1;
	if(s[0]==s1[0]&&s[1]==s1[1])
	{
		cout<<1;
		if(st[0]==st1[0]&&st[1]==st1[1])
		{
			cout<<1;
			if(st[2]>='A'&&st[2]<='C'&&st1[2]>='A'&&st1[2]<='C')
			{
				cout<<1;
				if(st[2]=='A'&&st1[2]=='C')cout<<0;
				else if(st[2]=='C'&&st1[2]=='A')cout<<0;
				else cout<<1;
			}
			else if(st[2]>='D'&&st[2]<='E'&&st1[2]>='D'&&st1[2]<='E')
			{
				cout<<1<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
