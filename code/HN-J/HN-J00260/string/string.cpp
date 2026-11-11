#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	struct cv
	{
		int number;
		char zm;
	} a[200005];
	struct cvv
	{
		int number;
		char zm;
	} aa[200005];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].number>>a[i].zm;
		cnt=cnt+a[i].number;
	}
	if(cnt%2==0)
	{
		int cs=0;
		int cntt;
		int zhongjian;
		for(int x=1;x<=n;x++)
		{
			cntt=cntt+a[x].number;
			if(cntt+a[x].number>cnt/2+1)
			{
				zhongjian=x;
				break;
			} 
		}
		for(int j=1;j<=n+2;j++)
		{
			if(j<zhongjian)
			{
				aa[j].number=a[j].number;
				aa[j].zm=a[j].zm;
			}
			else if(j==zhongjian)
			{
				aa[j].number=cnt-cntt-1;
				aa[j].zm=a[j].zm;
			}
			else if(j=zhongjian+1)
			{
				aa[j].number=1;
				aa[j].zm=a[j-1].zm;
			}
			else if(j=zhongjian+2)
			{
				aa[j].number=a[j].number-cnt+cntt;
				aa[j].zm=aa[j-2].zm;
			}
			else if(j>zhongjian+2)
			{
				aa[j].number=a[j-2].number;
				aa[j].zm=a[j-2].zm;
			}
		}
		int f=zhongjian;
		int j=zhongjian+2;
		while(f==0&&j==n+2)
		{
			if(a[f].zm!=a[j].zm)
			{
				if(a[f].number>a[j].number)
				{
					cs=cs+a[f].number-a[j].number;
					a[f].number=a[f].number-a[j].number;
					j++;	
				}
				else if(a[f].number<a[j].number)
				{
					cs=cs+a[j].number-a[f].number;
					a[j].number=a[j].number-a[f].number;
					f--;
				}
				else
				{
					cs=cs+a[j].number;
					f--;
					j++;
				}
			}
			else
			{
				if(a[f].number>a[j].number)
				{
					a[f].number=a[f].number-a[j].number;
					j++;	
				}
				else if(a[f].number<a[j].number)
				{
					a[j].number=a[j].number-a[f].number;
				f--;
				}
				else
				{
					f--;
					j++;
				}
			}
		}
		cout<<cs;
	}
	else
	{
		int cs=0;
		int cntt;
		int i=0;
		int ii=1;
		for(;ii<=n;ii++)
		{
			cntt=cntt+a[ii].number;
			if(cntt+a[ii].number>cnt/2+1)
			{
				i=ii;
				break;
			} 
		}
		for(int j=1;j<=n+1;j++)
		{
			if(j<i)
			{
				aa[j].number=a[j].number;
				aa[j].zm=a[j].zm;
			}
			else if(j==i)
			{
				aa[j].number=cnt-cntt;
				aa[j].zm=a[j].zm;
			}
			else if(j=i+1)
			{
				aa[j].number=a[j].number-cnt+cntt;
				aa[j].zm=a[j-1].zm;
			}
			
			else if(j>i+2)
			{
				aa[j].number=a[j-1].number;
				aa[j].zm=a[j-1].zm;
			}
		}
		i=ii;
		int j=i+1;
		while(i==0&&j==n)
		{
			if(a[i].zm!=a[j].zm)
			{
				if(a[i].number>a[j].number)
				{
					cs=cs+a[i].number-a[j].number;
					a[i].number=a[i].number-a[j].number;
					j++;	
				}
				else if(a[i].number<a[j].number)
				{
					cs=cs+a[j].number-a[i].number;
					a[j].number=a[j].number-a[i].number;
					i--;
				}
				else
				{
					cs=cs+a[j].number;
					i--;
					j++;
				}
			}
			else
			{
				if(a[i].number>a[j].number)
				{
					a[i].number=a[i].number-a[j].number;
					j++;	
				}
				else if(a[i].number<a[j].number)
				{
					a[j].number=a[j].number-a[i].number;
					i--;
				}
				else
				{
					i--;
					j++;
				}
			}
		}
		cout<<cs;
	}
	return 0;
}
