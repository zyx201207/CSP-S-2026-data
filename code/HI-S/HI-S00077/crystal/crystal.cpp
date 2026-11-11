#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num=1,k,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{	
			if(a[i]==a[i+1]) break;
			if(k-a[i]+a[j]>=0)
			{
				k=k-a[i]+a[j];
				num++;
			}
			else break;
		}
		ans=max(num,ans);
		num=1;
		k=m;
	}
	cout<<ans;
	return 0;
	//16:04
}
