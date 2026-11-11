#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=0,y=0;
	if(a==c)cout<<"1";
	else 
	{
		cout<<"0000";
		return 0;
	}
	x=int(b[0]-'0')*10+int(b[1]-'0');
	y=int(d[0]-'0')*10+int(d[1]-'0');
	if(x==y)cout<<"1";
	else 
	{
		cout<<"000";
		return 0;
	}
	int x1,x2;
	if('A'<=b[2]&&b[2]<='C')x1=1;
	else x1=2;
	if('A'<=d[2]&&d[2]<='C')x2=1;
	else x2=2;
	if(x1==x2)cout<<"1";
	else cout<<"0";
	if(x1==x2&&x1==2)cout<<"1";
	else if(x1==x2&&x1==1)
	{
		if(d[2]!='B'&&b[2]!='B')cout<<"0";
		else cout<<"1";
	}
	else cout<<"0";
	return 0;
}
