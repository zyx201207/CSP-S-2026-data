#include<bits/stdc++.h>

using namespace std;

char a[10],s[10],d[10],f[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>s>>d>>f;
	if(a[0]==d[0]&&a[1]==d[1])
	{
		cout<<1;
		if(s[0]==f[0]&&s[1]==f[1])
		{
			cout<<1;
			if((s[2]=='A'&&f[2]=='B')||(s[2]=='A'&&f[2]=='C')||(s[2]=='B'&&f[2]=='C')||(s[2]=='C'&&f[2]=='A')||(s[2]=='C'&&f[2]=='B')||(s[2]=='B'&&f[2]=='A')||(s[2]=='D'&&f[2]=='E')||(s[2]=='E'&&f[2]=='D'))
			{
				cout<<1;
				if((s[2]=='A'&&f[2]=='B')||(s[2]=='B'&&f[2]=='A')||(s[2]=='B'&&f[2]=='C')||(s[2]=='C'&&f[2]=='B')||(s[2]=='D'&&f[2]=='E')||(s[2]=='E'&&f[2]=='D'))
				{
					cout<<1;
				}
				else
				cout<<0;
			}
			else
			cout<<0<<0;
		}
		else
		cout<<0<<0<<0;
	}
	else
	cout<<0<<0<<0<<0;
	
	return 0;
} 
