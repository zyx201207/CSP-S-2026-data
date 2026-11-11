#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500050],cf[500050],qz[500050],qz2[500050];
int f=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			f=0;
		}
	} 
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++) 
	{
		cf[i]=a[i]-a[i-1];
		if(cf[i]!=cf[i-1])
		{
			f=0;
		}
	}
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+cf[i];
	for(int i=1;i<=n;i++) qz2[i]=qz2[i-1]+cf[i]*(i-1);
	
	//for(int i=1;i<=n;i++) cout<<qz2[i]<<' ';
	//cout<<endl;
	
	if(f==1)
	{
		int sum=0,k=1;
		while(sum<=m)
		{
			sum+=k;
			k+=cf[1];
		}
		cout<<k-1;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(qz2[j]-qz2[i]<=m)
			{
				ans=max(ans,(long long)j-i+1);
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
