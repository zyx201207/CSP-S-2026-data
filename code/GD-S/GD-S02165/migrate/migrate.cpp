#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,a[2000001],f=0;
void mig()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(d==1)
	{
	return;
	} 
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[i]>d)
		{
			break;
		}
		for(int j=i+3;j<=n;j++)
		{
		if(a[j]-a[j-1]>d)
		{
			break;
		}
			if((a[j]-a[i]+1)%d==0&&a[j]-a[i]>=d)
			{
				f++;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		f=0;
		mig();
		cout<<f<<"\n";
	}
	return 0;
}
