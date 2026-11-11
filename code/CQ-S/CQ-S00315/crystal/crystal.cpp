#include<bits/stdc++.h>
using namespace std;
const int N=500500;
long long n,m,a[N],ans,sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1) sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<sum[i]<<' ';
	}
	sort(a+1,a+1+n);
	long long l=1,r=1,k=0;
	while(r<=n)
	{
		while(k>m)
		{
			k-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		k+=(r-l)*(a[r]-a[r-1]);
//		cout<<l<<' '<<r<<' '<<k<<'\n';
	}
	cout<<ans;
	
	return 0;
}
