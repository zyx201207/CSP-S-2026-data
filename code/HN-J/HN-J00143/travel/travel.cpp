#include<bits/stdc++.h>
#define int long long
using namespace std;
int x1,x2;
string s1,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	string x=s1.substr(0,2);
	int z1=(x[0]-'0')*10+(x[1]-'0');
	x=s2.substr(0,2);
	int z2=(x[0]-'0')*10+(x[1]-'0');
	if(x1==x2)
	{
		cout<<1;
		if(z1==z2)
		{
			cout<<1;
			if(s1[2]<='C' and s2[2]<='C')
				cout<<1;
			else if(s1[2]>'C' and s2[2]>'C')
				cout<<1;
			else
			{
				cout<<"00";
				return 0;
			}
			if(s1[2]==s2[2]+1||s1[2]+1==s2[2])
				cout<<1;
			else
				cout<<0;
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

