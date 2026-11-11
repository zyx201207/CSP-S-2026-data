#include<bits/stdc++.h>
using namespace std;
int n[10000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,ans=0;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		cin>>n[i];
		if(b==0)
			if(n[i]>ans)
				ans=n[i];
		else
			ans+=n[i];
		
	}
	int j=0,k=0;
	if(b==0)
	{
		int s[1000000000];
		for(int i=0;i<a;i++)
		{
			for(int v=0;v<a;v++)
			{
				if(n[i]==n[v])
				{
					s[n[v]]++;
				}
			}
		}
		sort(s,s+ans);
		cout<<s[ans];
		return 0;
	}
	ans/=a;
	int n1[a+5],n2[a+5];
	for(int i=0;i<a;i++)
	{
		n1[i]=ans-n[i];
		if(n1[i]<0)
		{
			k+=n1;
			n2[j]=i;
			j++;
		}
		
	}
	k=0;
	ad=0;
	if(k<=b)
	{
		for(int i=0;i<a;i++)
		{	
			if(n1[i]<=0)
				ad++;
		}
		cout<<ad;
		return 0;
	} 
	return 0;
}
