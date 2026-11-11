#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if((b[0]==d[0])&&(b[1]==d[1]))
		{
			cout<<1;
			int x=b[2]-'A'+1,y=d[2]-'A'+1;
			if(x<=3&&y<=3)
				cout<<1<<(abs(x-y)==1);
			else if(x>3&&y>3)
				cout<<"11";
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}

