#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans,f[N],a[N],add;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++)
	{
		add+=1ll*f[i-1]*(a[i]-a[i-1]);
		while(add>m)
		{
			add-=a[i]-a[j];
			j++;
		}
		f[i]=i-j+1;
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
