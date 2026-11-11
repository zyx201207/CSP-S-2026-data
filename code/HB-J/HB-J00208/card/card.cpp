#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],book[400005],ans[500005];
inline int read()
{
	int x=0,f=1;char ch=getchar_unlocked();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar_unlocked();}
	while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar_unlocked();
	return x*f;
}
bool t=0;
int book1[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) 
    {
		a[i]=read();
		book1[a[i]]++;
		if(a[i]<a[i-1]) t=1;
	}
	if(t==0)
	{
		for(int i=1;i<=m;i++) book1[i]+=book1[i-1],printf("%d ",book1[i]);
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
		memset(book,0,sizeof(book));
		stack<int> q;
		for(int j=i;j<=n;j++)
		{
			if(book[a[j]]!=0)
			{
				for(int k=book[a[j]];k<j;k++) book[a[k]]=0;
			    while(!q.empty()&&q.top()!=a[j]) q.pop();
			    if(q.top()==a[j])q.pop();
				q.push(a[j]);
				book[a[j]]=j;
			}
			else
			{
				q.push(a[j]);
				book[a[j]]=j;
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
