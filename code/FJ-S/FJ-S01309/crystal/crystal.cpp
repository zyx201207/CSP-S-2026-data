#include<bits/stdc++.h>
using namespace std;
long long a[500001];
bool bo(long long x,long long y)
{
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		long long s=0,g=1;
		while(s<=m)
		{
			if(g>i)
			{
				break;
			}
			s+=a[i]-a[i-g];
			g++;
		}
		ans=max(ans,g);
	}
	cout<<ans-1;

	return 0;
}

