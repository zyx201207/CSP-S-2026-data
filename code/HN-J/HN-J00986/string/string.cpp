#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct st{
	int a;
	char b;
}g[200001];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>g[i].a>>g[i].b;
	int l=1,r=n,ans=0;
	while(l<r)
	{
		int minn=min(g[l].a,g[r].a);
		if(g[l].b!=g[r].b)ans+=minn;
		g[l].a-=minn;
		g[r].a-=minn;
		if(g[l].a==0)l++;
		if(g[r].a==0)r--;
	}
	cout<<ans;
	return 0;
}
