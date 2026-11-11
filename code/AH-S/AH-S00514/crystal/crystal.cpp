#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],b[N],ans;
unsigned long long m;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	long long i=1,j=2;
	unsigned long long sum=b[j]*(j-i);
	while(j<=n)
	{
		if(sum<=m) 
		{
			ans=max(ans,j-i+1);
			j++;
			sum+=b[j]*(j-i);
		}
		else
		{
			sum-=(a[j]-a[i]);
			i++;
		}
	}
	cout<<ans;
	return 0;
}
