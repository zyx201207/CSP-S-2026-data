#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int y;
int i;
int j;
int z;
int sum=0;
struct node
{
	int x;
	char ch;
}a[200010];
main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++)
	{
		cin>>a[k].x>>a[k].ch;
		y+=a[k].x;
	}
	z=y/2;
	if(y%2!=0)
		z++;
	i=1;
	j=n;
	for(;;)
	{
		if(y%2==0)
		{
			if(y-a[j].x<=z+1)
			{
				for(int k=i;k<=j+1;k++)
				{
					if(a[k].ch==a[j].ch)
						a[j].x--;
					else
					{
						sum+=a[k].x;
						a[j].x--;
					}
				}
				cout<<sum;
				return 0;
			}
			if(y-a[i].x<=z)
			{
				for(int k=j;k<=i;k--)
				{
					if(a[k].ch==a[i].ch)
						a[i].x--;
					else
					{
						sum+=a[k].x;
						a[i].x--;
					}
				}
				cout<<sum;
				return 0;
			}
		}
		else
		{
			if(y-a[j].x<z)
			{
				for(int k=i;k<=j+1;k++)
				{
					if(a[k].ch==a[j].ch)
						a[j].x--;
					else
					{
						sum+=a[k].x;
						a[j].x--;
					}
				}
				cout<<sum;
				return 0;
			}
			if(y-a[i].x<z)
			{
				for(int k=j;k<=i;k--)
				{
					if(a[k].ch==a[i].ch)
						a[i].x--;
					else
					{
						sum+=a[k].x;
						a[i].x--;
					}
				}
				cout<<sum;
				return 0;
			}
		}
		int cnt=min(a[i].x,a[j].x);
		if(a[i].ch==a[j].ch)
		{
			if(a[i].x<a[j].x)
			{
				i++;
				a[j].x-=a[i].x;
			}
			else if(a[i].x>a[j].x)
			{
				j--;
				a[i].x-=a[j].x;
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if(a[i].x<a[j].x)
			{
				i++;
				a[j].x-=a[i].x;
			}
			else if(a[i].x>a[j].x)
			{
				j--;
				a[i].x-=a[j].x;
			}
			else
			{
				i++;
				j--;
			}
			sum+=cnt;
		}
		y-=cnt;
		
		
	}
	return 0;
}//我爆数据了。
//再见了朋友们我的一等要死光光了。 
