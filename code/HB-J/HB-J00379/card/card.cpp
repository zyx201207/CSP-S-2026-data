#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int a[500010];
int ans[300010];
bool book[300010];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof book);
		for(int j=i;j<=n;j++)
		{
			if(book[a[j]])
			{
				while(s.top()!=a[j])
				{
					book[s.top()]=0;
					s.pop();
				}
				s.pop();
				book[a[j]]=0;
			}
			book[a[j]]=1;
			s.push(a[j]);
		}
		for(int i=1;i<=m;i++)
			ans[i]+=book[i];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
//"kards"
