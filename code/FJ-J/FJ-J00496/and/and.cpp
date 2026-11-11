#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1e9;
int p=1,h;
int a[30],shu[100005],shu2[100005];
int  zhao(int shu)
{
	if(!shu/2) 
	{
		a[1]++;
		return 1;
	}
	int j=1;
	while(shu/2)
	{
		a[j]+=shu%2;
		shu/=2;
		j++;
	}
	return j-1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>shu[i];	
	}
	for(int i=1;i<=n;i++)
	{
	shu2[i]=zhao(shu[i]);
	}
    while(a[30-p]<m)
    {
    	h++;
    	p++;
	}	
	for(int i=1;i<=n;i++)
	{
		if(shu2[i]==31-h)
		{
		cout<<shu[i];
		break;
		}
	}
	return 0;
}
