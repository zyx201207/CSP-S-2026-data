#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,ans;
char c[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int z=1,y=n;
	while(z<y)
	{
		if(c[z]==c[y])
		{
			int e=min(a[z],a[y]);
			a[z]-=e;
			a[y]-=e;
		}
		else
		{
			ans+=min(a[z],a[y]);
			int e=min(a[z],a[y]);
			a[z]-=e;
			a[y]-=e;
		}
		while(a[z]==0)
		{
			z++;
		}
		while(a[y]==0)
		{
			y--;
		}
	}
	cout<<ans;
}
