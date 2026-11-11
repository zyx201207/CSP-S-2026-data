#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=0,b=0,c=0,d=0; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	char a1,b1;
	for(int i=0;i<c1.size();i++) c+=c1[i]-'0';
	for(int i=0;i<c2.size();i++) d+=c2[i]-'0';
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			a+=s1[i]-'0';
		}
		else a1=s1[i];
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			b+=s2[i]-'0';
		}
		else b1=s2[i];
	}
	if(c1==c2)
	{
		cout<<1;
		if(a==b)
		{
			cout<<1;
			if(a1>='A'&&a1<='C'&&b1>='A'&&b1<='C'||a1>='D'&&a1<='F'&&b1>='D'&&b1<='F')
			{
				cout<<1;
				if(a1=='A'&&b1=='B') cout<<1;
				else if(a1=='B'&&(b1=='C'||b1=='A')) cout<<1;
				else if(a1=='C'&&b1=='B') cout<<1;
				else if(a1=='D'&&b1=='F') cout<<1;
				else if(a1=='F'&&b1=='D') cout<<1;
				else cout<<0;
				return 0;
			}
			else cout<<"00";
			return 0;
		}
		else cout<<"000";
		return 0;
	}
	else cout<<"0000";
	return 0;
}

