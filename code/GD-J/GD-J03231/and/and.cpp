#include<bits/stdc++.h>
using namespace std;
int a[50000];
long long n,m,e;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	long long ans=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			ans=a[1];
			ans=(ans&a[i]);
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k=(a[i]&a[j]);
				ans=max(ans,k);
			}
		}
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans=(ans&a[i]);
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
