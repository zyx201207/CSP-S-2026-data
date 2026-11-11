#include<bits/stdc++.h>
using namespace  std;
int n;
long long ans=0;
struct zf
{
	int a;
	char x;
}f[511000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i].a>>f[i].x;
	}
	for(int i=1,j=n;i<j;)
	{
		if(f[i].x==f[j].x)
		{
			if(f[i].a<f[j].a)
			{
				f[j].a-=f[i].a;
				i++;
			}
			else
			{
				f[i].a-=f[j].a;
				j--;
			}
		}
		else
		{
			ans+=min(f[i].a,f[j].a);
			if(f[i].a<f[j].a)
			{
				f[j].a-=f[i].a;
				i++;
			}
			else
			{
				f[i].a-=f[j].a;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
