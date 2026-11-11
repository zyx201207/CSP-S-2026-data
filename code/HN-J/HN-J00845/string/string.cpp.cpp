#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,cum=0,j,ss;
	int zj=0,ui=0;
	char df;
	cin>>a;
	char s[2000000];
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		ss=cum+b;
		cin>>df;
		for(int i=cum;i<ss;i++)
		{
			s[i]=df;
		}
		cum=b+cum;
	}
	if(cum%2==0)
	{
		zj=(cum-2)/2;
		for(int i=0;i<=zj;i++)
		{
			j=zj+i+1;
			if(s[i]!=s[j])
			ui++;
		}
	}else
	{
		zj=(cum-1)/2;
		for(int i=0;i<zj;i++)
		{
			j=zj+i+1;
			if(s[i]!=s[j])
			ui++;
		}
	}
	cout<<ui;
	return 0;
}
