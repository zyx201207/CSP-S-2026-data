#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","c",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(((a[0]-'0')*10+a[1]-'0')!=((c[0]-'0')*10+c[1]-'0'))
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(((b[0]-'0')*10+b[1]-'0')!=((d[0]-'0')*10+d[1]-'0'))
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((b[2]-'C'<=0&&d[2]-'C'>0)||(b[2]-'C'>0&&d[2]-'C'<=0))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(b[2]-d[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
