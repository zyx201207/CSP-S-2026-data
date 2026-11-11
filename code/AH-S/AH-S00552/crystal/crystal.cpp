#include<bits/stdc++.h>
using namespace std;
long long sum,ans=-1,n,m,a[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++) 
	{
		for(long long j=i;j>=1;j--)
		{
			sum=0;
			for(long long k=j;k<=i;k++)
			{
				sum+=a[i]-a[k];
				if(sum>m)
				{
					ans=max(ans,i-k);
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
