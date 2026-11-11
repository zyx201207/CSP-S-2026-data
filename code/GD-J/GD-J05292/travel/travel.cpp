#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		cout<<"0000";
	else
	{
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1])
			cout<<"000";
		else
		{
			cout<<1;
			if((s1[2]<='C')!=(s2[2]<='C'))
				cout<<"00";
			else
			{
				cout<<1;
				if((s1[2]!='C'||s2[2]!='A')&&(s1[2]!='A'||s2[2]!='C'))
					cout<<1;
				else
					cout<<0;
			}
		}
	}
	return 0;
} 
