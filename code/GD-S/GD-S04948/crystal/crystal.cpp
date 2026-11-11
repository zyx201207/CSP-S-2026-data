#include<bits/stdc++.h> 
using namespace std;
int m,n,a[50000000],pa[50000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=n/2+1;
	for(int i=1;i<=n;i++)
	{
		pa[i]=a[mid]-a[i];
	}
	int t=0,ans=1;

	
	while(m>0)
	{
		if(pa[ans]<=m &&pa[ans]!=0)
		{
			
			m-=pa[ans];
			ans++;
			t++;
		}
		else
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(pa[i]==0)
		{
			t++;
		}
	}
	
	cout<<t;
	return 0;
}
