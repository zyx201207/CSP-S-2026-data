#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],s[600000],ans,cnt=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i]; 
		while(a[i]*(i-cnt)>m+s[i-1]-s[cnt-1])cnt++;
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
}
