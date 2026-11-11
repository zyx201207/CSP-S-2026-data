#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[500002];
int a[500005];
bool b[500002];
bool b2[500002];
int ans[500002];
int top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool ok=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			ok=false;
			break;
		}
	}
	if(ok==true)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=max(ans[a[i]],i);
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}	
	}else{
		for(int k=1;k<=n;k++)
		{
			while(top)
			{
				st[top]=0;
				top--;
			}
			top=0;
			memset(b,false,sizeof(b));
			memset(b2,false,sizeof(b2));
			for(int i=k;i<=n;i++)
			{
				int x=a[i];
				if(b[x])
				{
					int pos=0;
					for(int j=1;;j++)
					{
						if(st[j]==x)
						{
							pos=j;
							break;
						}
					}
					for(top;top>pos;top--)
					{
						st[top]=0;
					}
					top=pos;
				}else{
					st[++top]=x;
					b[x]=true;
				}
			}
			for(int i=1;i<=top;i++)
			{
				b2[st[i]]=true;
			}
			for(int i=1;i<=m;i++)
			{
				if(b2[i])
				{
					ans[i]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}	
	}
	
}
