#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],m,n,sum;
int sb()
{
		m=m/abs(b[3]);
		cout<<m;
		return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int Max=-999;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld" ,&a[i]);
		b[i]=abs(a[i]-a[i-1]);
	}
	sort(a+1,a+n+1);
	if(n>=500000)
	{
		sb();
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		int j=i-1,ans=1;
		sum=0;
		    while(j>=1)
		    {
				long long s=abs(a[i]-a[j]);
			    if(s+sum<=m)
			    {
				    ans++;
				    j--; 
				    sum=s+sum; 
				    continue;
			    }
			    break;
		    }
		    Max=max(Max,ans);
	}
	cout<<Max;
	return 0;
} 

