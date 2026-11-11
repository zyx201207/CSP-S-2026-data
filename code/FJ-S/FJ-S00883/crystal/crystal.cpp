#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],ans=1,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=2;
	while(r<=n)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		if(sum>m)
		{
			ans=max(ans,r-l);
			while(sum>m)
			{
				sum-=(a[r]-a[l]);
				l++;	
			}		
		}
		r++;
	}
	cout<<ans;
	return 0;
} 
