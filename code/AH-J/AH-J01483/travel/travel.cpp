#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	int sum=0,cnt=0;
	for(int i=0;i<=1;i++)
	{
		sum=sum*10+int(sa[i]-48);
		cnt=cnt*10+int(sb[i]-48);
	}
	if(sum==cnt&&ca==cb)
	{
		cout<<"1";
	}
	else 
	{
		cout<<"0";
	}
	if(((sa[2]>='A'&&sa[2]<='C'&&sb[2]>='A'&&sb[2]<='C')||(sa[2]>='D'&&sa[2]<='F'&&sb[2]>='D'&&sb[2]<='F'))&&ca==cb&&sum==cnt)
	{
		cout<<"1";
		if(sa[2]=='B'||sb[2]=='B'||sa[2]=='D'||sa[2]=='F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"00";
	}
	return 0;
}
