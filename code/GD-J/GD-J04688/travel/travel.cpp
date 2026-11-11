#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<=n;++i)
string c1,s1,c2,s2;
void sol()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<"1";
			if(s1[2]<='C' && s2[2]<='C')
			{
				cout<<"1";
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2])cout<<"1";
				else cout<<"0";
				return;
			}
			else if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D')
			{
				cout<<"11";
				return;	
			}
			else
			{
				cout<<"00";
				return;
			}
		}
		else
		{
			cout<<"000";
			return;
		}
	}
	else
	{
		cout<<"0000";
		return;
	}
}
int main()
{
	sol();
	return 0;
}
