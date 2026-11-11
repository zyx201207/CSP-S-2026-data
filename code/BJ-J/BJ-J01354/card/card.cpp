#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans[N];
int head,tail,desk[N],last[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	deque<int> q;
	for (int i=1;i<=n;i++)
	{
		head=1,tail=0;
		for (int j=1;j<=m;j++) last[j]=-1;
		for (int j=i;j<=n;j++)
		{
			if (last[a[j]]==-1) desk[++tail]=a[j],last[a[j]]=tail;
			else 
			{
				for (int k=last[a[j]]+1;k<=tail;k++)
				{
					last[desk[k]]=-1;
				}
				tail=last[a[j]];
			}
		}
		for (int j=head;j<=tail;j++)
		{
			ans[desk[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
