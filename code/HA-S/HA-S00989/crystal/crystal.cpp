#include<bits/stdc++.h>
using namespace std;
long long l[500005];
long long n,m,sum=0,ans=1;
long long k=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	sort(l,l+n);
	for(long long i=n-1;i>=0;i--)
	{
		for(long long j=i-1;j>=0;j--)
		{
			if(sum>=m)
			{
				break;
			}
			if(sum+(l[i]-l[j])>m)
			{
				break;
			}	
			sum+=(l[i]-l[j]);
			ans++;
		}
		k=max(k,ans);	
		ans=1;
		sum=0;
	}
	cout<<k;
	return 0;
}
