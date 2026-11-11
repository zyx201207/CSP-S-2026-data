#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],t[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int q=1;q<=n;q++)
	{
		for(int i=q;i<=n;i++)
		{
			t[a[i]]++;
			if(t[a[i]]==2)
			{
				t[a[i]]--;
				for(int j=i-1;a[j]!=a[i];j--)
				{
					t[a[j]]--;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			b[i]+=t[i];
			t[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
