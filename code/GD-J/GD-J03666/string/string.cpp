#include<bits/stdc++.h>
using namespace std;
struct l
{
	int a;
	char c;
}y[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,index_;
	long long x=0,z,sum=0;
	cin>>n;
	index_=n;
	for(int i=1;i<=n;i++)
	{
		cin>>y[i].a>>y[i].c;
		x+=y[i].a;
	}
	z=x/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=y[i].a;j++)
		{
			if(y[index_].c!=y[i].c)
			{
				sum++;
				y[index_].a--;
				x--;
				if(x==z)
				{
					cout<<sum;
					return 0;
				}
				if(!y[index_].a)
				{
					index_--;
				}
			}
			else
			{
				if(y[index_].a>y[i].a)
				{
					if(x-y[i].a<=z)
					{
						cout<<sum;
						return 0;
					}
					x-=y[i].a;
					y[index_].a-=y[i].a;
					break;
				}
				else if(y[i].a>y[index_].a)
				{
					if(x-y[index_].a<=z)
					{
						cout<<sum;
						return 0;
					}
					x-=y[index_].a;
					j+=y[index_].a;
					index_--;
				}
				else
				{
					if(i==index_)
					{
						cout<<sum;
						return 0;
					}
					if(x-y[i].a<=z)
					{
						cout<<sum;
						return 0;
					}
					x-=y[i].a;
					index_--;
					break;
				}
			}
		}
	}
	return 0;
}
