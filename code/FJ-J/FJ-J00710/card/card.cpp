#include<bits/stdc++.h>
using namespace std;
int have[200100];
int n,m;
int a[200100];
int cnt[300100];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>have[i];
	for(int k=1;k<=n;k++)
	{
		int top=0;
		memset(a,0,sizeof(a));
		for(int i=k;i<=n;i++)
		{
			int x=have[i];
			for(int i=1;i<=top;i++)
			{
				if(a[i]==x)
				{
					top=i-1;
					break;
				}
			}
			top++;
			a[top]=x;
		}
		for(int i=1;i<=top;i++) cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

