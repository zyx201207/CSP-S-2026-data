#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
bool c[300005];
stack<int>s;
void p(int l,int r){
	memset(c,0,sizeof(c));
	while(!s.empty())s.pop();
	for(int i=l;i<=r;i++)
	{
		if(c[a[i]]==0)
		{
			c[a[i]]=1,s.push(a[i]);
		}
		else
		{
			while(s.top()!=a[i]&&!s.empty())
			{
				c[s.top()]=0;
				s.pop();
			}
			c[a[i]]=1;s.push(a[i]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(c[i]==1)b[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		p(i,n);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
