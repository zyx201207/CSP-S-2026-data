#include<bits/stdc++.h>
using namespace std;
long long a[500000+5];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	long long n,m,cnt=0,sum=0,cmp=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;++i)
	{
		cmp+=(a[i]-a[i-1])*sum;
		sum++;
		while(cmp>m)
		{
			cmp-=cnt;
			cnt-=(a[j+1]-a[j]);
			sum--;
			j++;
		}
		cnt+=(a[i+1]-a[i]);
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
