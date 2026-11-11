#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans;
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>5000) 
	{
		long long p=1;
		while(p<=n) 
		{
			long long dj=(a[1]+a[p])*p/2;dj-=p;
			if(m>=dj) 
			{
				ans=max(ans,p);
				p++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		long long d[500005]; 
		for(int j=1;j<=n;j++) 
		{
			d[j]=a[i]-a[j];
		}
		sort(d+1,d+n+1);
		long long cnt=0,tmp=m;
		for(int j=1;j<=n;j++) 
		{
			if(d[j]<0) continue;
			if(m<d[j]) break;
			cnt++;
			m-=d[j];
		}
		m=tmp;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
