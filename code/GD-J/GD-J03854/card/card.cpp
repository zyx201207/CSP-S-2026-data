#include<bits/stdc++.h>
using namespace std;
int a,s,aa[501000],ss[501000],as[501000],ff[501000],gg[501000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>s;
	for(int i=1;i<=a;i++)
	{
		cin>>aa[i];
	}
	for(int i=a;i>=1;i--)
	{
		ff[i]=1;
		if(gg[aa[i]]==0)
		gg[aa[i]]=i;
	}
	for(int i=1;i<=a;i++)
	{
		ff[gg[aa[i]]+1]=ff[gg[aa[i]]+1]+ff[i];
		as[aa[i]]=as[aa[i]]+ff[i];
	}
	for(int i=1;i<=s;i++)
	{
		cout<<as[i]<<" ";
	}
}
