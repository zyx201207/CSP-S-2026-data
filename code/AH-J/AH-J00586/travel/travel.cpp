#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else
	{
		string x=b,y=d;
		x.erase(2,1);y.erase(2,1);
		if(x!=y)cout<<"1000";
		else
		{
			if((b[2]>='D'&&d[2]<='C')||(d[2]>='D'&&b[2]<='C'))cout<<"1100";
			else
			{
				if(abs(ll(b[2])-ll(d[2]))!=1)cout<<"1110";
				else cout<<"1111";
			}
		}
	}
}
