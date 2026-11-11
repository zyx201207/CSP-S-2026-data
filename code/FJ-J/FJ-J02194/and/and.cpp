#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],p[200010],ans;
void dp(long long k,long long s)
{
	if(k==0)ans=max(s,ans);
	else
	{
		long long num=0,b=0;
		for(long long j=n-1;j>0;j--)
			if(!p[j]&&(s&a[j])>num)num=(s&a[j]),b=j;
		p[b]=1;dp(k-1,num);p[b]=0;
	}
}
int main()
{
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=n;i>0;i--)
		dp(m-1,a[i]);
	cout<<ans;
 	return 0;
}
