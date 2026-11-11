#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[300005];
bool flag[300005];

bool xi(int b,int e,int l,int a[])
{
	for(int k=--e;k>=b;k--) for(int m=++e;m<=l;m++) if(a[k]==a[m] && a[k]!=a[e]) return false;
	return true;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++) flag[i]=true;
		for(int j=n;j>=i;j--)
		{
			if(xi(i,j,n,a) && flag[a[j]])
			{
				cnt[a[j]]++;
				flag[a[j]]=false;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

