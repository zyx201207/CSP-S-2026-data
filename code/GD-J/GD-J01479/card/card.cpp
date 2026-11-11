#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),ans(m+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> b(m+1,1e6);
		vector<bool> f(n+1);
		for(int j=i;j<=n;j++)
		{
			f[j]=1;
			if(b[a[j]]!=1e6)
			{
				for(int k=b[a[j]];k<j;k++)
					f[k]=0;
			}
			b[a[j]]=j;
		}
		for(int j=1;j<=n;j++)
			if(f[j]&&b[a[j]]>0)
			{
				ans[a[j]]++;
				b[a[j]]=-1;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
