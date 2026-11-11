//样例全部测试通过 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	string pai[2];
	pai[0]=b[0];//座位号都有两位
	pai[1]=d[0];
	pai[0]+=b[1];
	pai[1]+=d[1];
	if(pai[0]==pai[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char seat[2];
	seat[0]=b[2];
	seat[1]=d[2];
	if((seat[0]<='C'&&seat[1]<='C')||('C'<seat[0]&&'C'<seat[1]))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(seat[0]+1==seat[1]||seat[1]+1==seat[0])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
