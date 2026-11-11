#include<bits/stdc++.h>
using namespace std;
char c[3]={'A','B','C'};
char c1[3]={'D','E','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b[1]!=d[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	int flag=1;
	for(int i=0;i<=2;i++)
		if(b[2]==c1[i])
			flag=0;
	int flag1=1;
	for(int i=0;i<=2;i++)
		if(d[2]==c1[i])
			flag1=0;
	if(flag!=flag1)
	{
		cout<<"00";
		return 0;
	 } 
	cout<<1;
	int x=b[2]-'A';
	int y=d[2]-'A';
	if(abs(x-y)==1)
		cout<<1;
	else
		cout<<0;
	return 0;
} 
