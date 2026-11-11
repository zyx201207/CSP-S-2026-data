#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int a,b;
	string s,st;
	cin>>a>>s>>b>>st;
	if(a==b)
	{
		cout<<1;
		if(s[0]==st[0]&&s[1]==st[1])
		{
			cout<<1;
			if(s[2]<='C'&&st[2]<='C')
			{
				cout<<1;
				if(abs(s[2]-st[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(s[2]>='D'&&st[2]>='D')
			{
				cout<<11;
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
//气死我了，还自动去除前导零，开了5min
//8:46AC 
