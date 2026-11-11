#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ne[500005];
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(m==0)
	{
		long long cnt=1,ans=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]){cnt++;ans=max(ans,cnt);}
			else cnt=1;
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++)ne[i]=(a[i]-a[i-1])*(i-1)+ne[i-1];
	for(int i=1;i<=n;i++)if(m<ne[i]){cout<<i-1;return 0;}
	return 0;
}
