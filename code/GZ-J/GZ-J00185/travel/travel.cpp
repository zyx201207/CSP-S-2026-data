//GZ-J00185 ³ÂÕıÁú
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1])
	{
		cout<<"1";
		if((b[2]-'A'>=3&&d[2]-'A'<=2)||(b[2]-'A'<=2&&d[2]-'A'>=3))
		{
			cout<<"00";
			return 0;
		}
		cout<<"1";
		if(abs((b[2]-'A')-(d[2]-'A'))==1) cout<<"1";
		else cout<<"0";
	}
	else
	{
		cout<<"000";
	}
	return 0;
}

