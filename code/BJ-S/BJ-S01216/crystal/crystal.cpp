#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,p[10001],c[10001],mx=0;
bool cmp(int x,int y)
{
	return x < y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	
	sort(c+1,c+n+1,cmp);
	p[0]=0;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]+c[i];
	}
	for(long long i=1;i<n;i++)
	{
		for(long long j=i;j<n;j++)
		{
			if((j-i+1)*c[j+1]-(p[j]-p[i-1])<=m)
			{
				mx=max(mx,j-i+2);
			}
				
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
