#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool f[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)if(((a[j]>>i)&1)&&!f[j])cnt++;
		if(cnt<m)continue;
		for(int j=1;j<=n;j++)if(!((a[j]>>i)&1))f[j]=true;
		ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}

