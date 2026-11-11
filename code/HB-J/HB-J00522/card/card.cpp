#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n,m;
vector<int> mp[N];
int ans[N],a[N];
bool book[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof(book));
		for(int j=n;j>=i;j--)
		{
			if(book[a[j]]) 
			{
				for(int k=j+1;k;k++) 
				{
					if(a[k]==a[j]) break;
					ans[k]--;
				}
				break;
			}
			book[a[j]]=1;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
 */
