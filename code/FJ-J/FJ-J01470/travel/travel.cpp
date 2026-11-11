#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2))
		{
			cout<<1;
			if((b[2]<='C'&&d[2]<='C'))
			{
				cout<<1;
				if(abs((int)b[2]-(int)d[2])==1) cout<<1;
				else cout<<0;
			}
			else if(b[2]>='D'&&d[2]>='D') cout<<11;
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
