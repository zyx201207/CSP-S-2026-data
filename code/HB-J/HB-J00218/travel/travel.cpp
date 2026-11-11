#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
int n,m,ans;
int side(string s)
{
	char ch=s[2];
	return (ch>='A'&&ch<='C');
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(side(s1)==side(s2))
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
