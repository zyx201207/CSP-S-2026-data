#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],sum[N],maxn=-1e6;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		long long ssum=sum[a[i]];
		long long ans=0;
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]==a[j])
			continue;
			ans+=(a[i]-a[j]);
			if(ans<=m){
				ssum++;
				maxn=max(maxn,ssum);
			}
			else
			break;
		}
	}
	cout<<maxn;
	return 0;
}
