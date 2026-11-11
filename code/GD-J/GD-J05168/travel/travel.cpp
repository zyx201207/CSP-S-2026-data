#include<bits/stdc++.h>
using namespace std;
bool cd(string a,string b)
{
	if(a[2]=='C'&&b[2]=='D') return 1;
	if(a[2]=='D'&&b[2]=='C') return 1;
	return 0;
}
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(s1[2]<'D'&&s2[2]>'C'||s2[2]<'D'&&s1[2]>'C') cout<<0<<0;
			else
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1&&!cd(s1,s2)) cout<<1;
				else cout<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
