#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(false)
using namespace std;
int T,n,m;
string s1,s2,t1,t2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Tie,cin>>s1>>s2>>t1>>t2;
	if(s1==t1)
	{
		cout<<"1";
		if(s2.substr(0,2)==t2.substr(0,2))
		{
			cout<<"1";
			if(s2.back()<='C'&&t2.back()<='C')
			{
				cout<<"1";
				if(abs((int)s2.back()-(int)t2.back())==1) cout<<"1";
				else cout<<"0";
			}
			else if(s2.back()>'C'&&t2.back()>'C') cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}//100pts