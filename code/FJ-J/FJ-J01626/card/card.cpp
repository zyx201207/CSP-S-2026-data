#include<bits/stdc++.h>
using namespace std;
int n,m,e,c[500050],b[500050],d[500050],a[500050],j;
queue<int>q,w;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q.push(a[i]);
	}
	e=1;
	while(e<=n)
	{
		int r=q.front();
		q.pop();
		if(!c[r])
		{
			j++;
			b[j]=r;//第j张牌的点数 
			c[r]=j;//点数r所在的位置 
		}
		else
		{
			for(int i=j;i>c[r];i--)
			{
				c[b[i]]=0;
				b[i]=0;
			}
			j=c[r];
		}
		if(q.empty())
		{
			e++;
			for(int i=1;i<=j;i++)
			{
				d[b[i]]++;
			}
//			for(int i=1;i<=j;i++)
//			{
//			cout<<b[i]<<"　"; 
//			}
//			cout<<endl;
			for(int i=e;i<=n;i++)
			{
				
				q.push(a[i]);
			}
			j=0;
			memset(c,0,sizeof(c));
			memset(b,0,sizeof(b));
		}
	}
	for(int i=1;i<=m;i++)
	{
//		cin>>e;
//		if(d[i]!=e)cout<<i<<endl<<endl<<endl;
		cout<<d[i]<<"　"; 
	}
	return 0;
 } 
