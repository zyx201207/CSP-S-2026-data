#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int b[30005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		long long s[500005]={},k=1;
		for(int j=i;j<=n;j++)
		{
			s[k]=a[j];
			j=b[a[j]];
			k++;
		}
		for(int l=1;l<=k;l++)ans[s[l]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
