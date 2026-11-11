#include <bits/stdc++.h>
using namespace std;
int n,m;
int  a[500005],q[500005],cnt[500005]; 
int b[500005];
int top=0,top1=0;
void push(int x)
{
	top++;
	top1=top;
	q[top]=x;
}
void back(int x)
{
	while(true)
	{
		if(q[top1]==x)break;
		b[q[top1]]=0;
		top1--;
	}
	top=top1;
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {

    	for(int j=i;j<=n;j++)
    	{
    		if(b[a[j]]==0)
			{
				push(a[j]);
				b[a[j]]=1;
			}
			else back(a[j]);
		}
		for(int i=1;i<=m;i++)
		{
			if(b[i]>0)cnt[i]++;
		}
		memset(q,0,sizeof(q));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
 
