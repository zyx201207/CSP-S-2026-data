#include<bits/stdc++.h>
using namespace std;
int a[500100],b[500100],c,maxc[500100],minc[500100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			cin>>c;
			if(maxc[i]<c)
			{
				maxc[i]=c;
			}
			if(minc[i]>c)
			{
				minc[i]=c;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		long long k=(maxc[i]-minc[i]);
		if(k%2==0)
		{
			cout<<k/2/2<<'\n';
		} 
		else
		{
			cout<<k/2/2+1<<'\n';
		}
		
	}
	return 0;
}
