#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>b>>a>>d>>c;
	if(b==d)
	{
		cout<<1;
		if(a.substr(0,2)==c.substr(0,2))
		{
			cout<<1;
			if(a[2]>='A'&&a[2]<='C'&&c[2]>='A'&&c[2]<='C')
			{
				cout<<1;
				if(a[2]=='B'||c[2]=='B')cout<<1;
				else cout<<0;
			}
			else if((a[2]=='D'||a[2]=='F')&&(c[2]=='D'||c[2]=='F'))cout<<11;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
