#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,m;
struct node
{
	int num,k;
}b[5005];
bool sq(node x,node y)
{
	if(x.k==y.k)
	{
		return x.num<y.num;
	}
	return x.k>y.k;
}
bool sp(node x,node y)
{
	if(x.num==y.num)
	{
		return x.k<y.k;
	}
	return x.num<y.num;
}

int main()
{
	freopen("crystal.in","r",in);
	freopen("crystal.out","w",out);
	cin>>n>>m;
	int x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==b[x].num)
		{
			b[x].k++;
		}
		else if(a[i]!=b[x].num)
		{
			x++;
			b[x].num=a[i];
			b[x].k++;
		}	
	}
	sort(b+1,b+x+1,sq);
	int nx=b[1].num,kx=b[1].k;
	sort(b+1,b+x+1,sp);
	int umax;
	for(int i=1;i<=x;i++)
	{
		if(b[i].num==nx)
		{
			umax=i;
			break;
		}
	}
	int ans=kx;
	int u=umax-1;
	for(;;)
	{
		if(u>1&&u<umax)
		{
			if(b[u].num==b[umax].num)
			{
				u--;
			}
			if(b[u].num<b[umax].num)
			{
				if((m-(b[umax].num-b[u].num)*b[u].k)>=0)
				{
					m=m-(b[umax].num-b[u].num)*b[u].k;
					ans=ans+b[u].k;
					b[u].num=b[umax].num;
				}
				else
				{
					break;
				}
			}
		}

		if(u==1&&m>0)
		{
			u=umax+1;
		}
		
		if(u==umax)
		{
			u++;
		}
		
		if(u>umax)
		{
			if((m-(b[u].num-b[umax].num)*ans)>=0)
			{
				ans=ans+b[u].k;
				m=m-(b[u].num-b[umax].num)*ans;
				umax=u;
			}
			else
			{
				cout<<ans;
				return 0;
			}
		}
		
		if(u==x)
		{
			break;
		}
	}

	if(m>=0)
	{
		if(u>1&&u<umax)
		{
			for(;;)
			{
				if(m-(b[umax].num-b[u].num)>0)
				{
					ans++;
					b[u].k--;
					m=m-(b[umax].num-b[u].num);
				}
				else
				{
					cout<<ans;
					return 0;
				}
			}
		}
	}
	if(m==0)
	{
	cout<<ans;
	}
	return 0;
}
