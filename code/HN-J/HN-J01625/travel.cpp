#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]!=d[0]||b[1]!=d[1])
	{
		cout<<"1000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
	{
		if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))cout<<"1110";
		else cout<<"1111";
		return 0;
	}
	cout<<"1100";
	return 0;
}
