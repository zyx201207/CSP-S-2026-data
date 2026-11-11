#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long c[N];
long long sum;
long long ans,cnt;
int main()
{
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long i,j;
	cin>>a[1];
	for(i=2;i<=n;i++)
	{
		cin>>a[i];
		c[i-1]=a[i]-a[i-1];
	}
	long long temp;
	for(i=1;i<n;i++)
	{
		cnt=sum=0;
		temp=m;
		j=i;
		while(j<=n)
		{
			sum+=c[j];
			if(temp-sum>=0)
			{
				cnt++;
				j++;
			}
			else
			{
				break;
			}
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
