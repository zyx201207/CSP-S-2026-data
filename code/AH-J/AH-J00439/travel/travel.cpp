#include<bits/stdc++.h>
using namespace std;
string b,d;
long long a,c,lb,ld;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	lb=b.size();
	ld=d.size();
	if(a==c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b.substr(0,2)==d.substr(0,2))
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((b[lb-1]<='C'&&d[ld-1]<='C')||(b[lb-1]>'C'&&d[ld-1]>'C'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(b[lb-1]-1==d[ld-1]||b[lb-1]+1==d[ld-1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
}
