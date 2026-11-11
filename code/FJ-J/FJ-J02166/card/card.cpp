#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int e[500010];
long long ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);      //¼ÇµÃÉ¾×¢ÊÍ
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		e[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;)
		{
			//cout<<a[j]<<" ";
			ans[a[j]]++;
			j=e[a[j]]+1;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
