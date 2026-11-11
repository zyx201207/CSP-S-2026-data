#include<bits/stdc++.h>
using namespace std;
	int m,n,a[1000],g[1000],d,sum=0,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i]=a[i];
}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum=1;
			d=m;
			while(d>0)
			{
			if(g[i]<g[j])
			{
				g[i]=g[j];
				d=d-g[j]+g[i];
				i++;
				sum++;
			}
				else
			{
				num=max(num,sum); 
				break;
			}
			}
		}
}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
