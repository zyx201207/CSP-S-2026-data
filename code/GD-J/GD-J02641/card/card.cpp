#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005],ans[300005];
int q[100000005],tail=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		tail=0;
		memset(t,0,sizeof(t));
		for (int j=i;j<=n;j++)
		{
			q[++tail]=a[j];
			if (t[a[j]]!=0)
			{
				for (int k=t[a[j]]+1;k<tail;k++)
					t[q[k]]=0;
				tail=t[a[j]];
			}
			else t[a[j]]=tail;
		}
		for (int j=1;j<=tail;j++)
			ans[q[j]]++;
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
