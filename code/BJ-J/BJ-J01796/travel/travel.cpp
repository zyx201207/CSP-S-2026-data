#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string str,stra,strb;
	cin>>str;
	n=int(str[0])*10+int(str[1]);
	m=int(str[7])*10+int(str[8]);
	stra=substr(str.length()+3,3);
	strb=substr(str.length()+10,3);
	if(n==m)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int flag=1;
	for(int i=0;i<2;i++)
	{
		if(stra[i]!=strb[i])
		{
			flag=0;
		}
	}
	cout<<flag;
	if(flag==0)
	{
		cout<<"00";
		return 0;
	}
	if(stra[2]>='A'&&stra[2]<='C')
	{
		if(strb[2]>='D')
		{
			cout<<"00";
			return 0;
		}
		cout<<1;
	}
	else
	{
		if(strb[2]>='D')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(abs(int(stra[2]-strb[2]))==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
