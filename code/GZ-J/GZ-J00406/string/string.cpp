//GZ-J00406  ËçÑôÏØËçÑôÖÐÑ§ ÌïÑÔÎ÷ 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,num,x=0;
	char b,a[1000000],a1[500000],a2[500000];
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>num;
		cin>>b;
		for(int j=0;j<num;j++)
		{
			a[x++]=b;
		}
	}
	if(x%2==1)
	{
		for(int i=0;i<x/2;i++)a1[i]=a[i];
		for(int i=x-1;i>x/2;i--)a2[x-i-1]=a[i];
	}
	else
	{
		for(int i=0;i<x/2;i++)a1[i]=a[i];
		for(int i=x-1;i>=x/2;i--)a2[x-i-1]=a[i];
	}
	int ans=0;
	for(int i=0;i<x/2;i++)
	{
		if(a1[i]!=a2[i])ans++;
	}
	cout<<ans;
	return 0;
}

