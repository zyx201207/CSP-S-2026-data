#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXN1=3e5+5;
int a[MAXN],last[MAXN1],s[MAXN],tot[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		last[a[i]]=i;
		++tot[a[i]];
	}
	for (int i=1;i<=n;++i)
	{
		if (tot[a[i]]==1)
		{
			continue;
		}
		t=i;
		for (int j=i+1;j<=n;++j)
		{
			if (a[i]==a[j])
			{
				for (int k=t+1;k<j;++k)
				{
					s[a[k]]=max(s[a[k]],t);
				}
				t=j;
			}
		}
	}
	for (int i=1;i<=m;++i)
	{
		cout<<last[i]-s[i]<<" ";
	}
	return 0;
}
