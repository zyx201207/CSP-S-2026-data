#include <bits/stdc++.h>
using namespace std;
struct no{
	long long c;//shu
	long long h;//cha
	long long r;//all cha
};
int cmp(no a,no b)
{
	return a.c<b.c;
}
long long n,m,t=0x3f3f3f3f,tt,s=2;
no a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
			for(int j=1;j<=n;j++)
			{
					if(i!=j)
					{
							if(i<j)
							{
								a[i].r+=a[j].c-a[i].c;
							}
							else if(i>j)
							{
								a[i].r+=a[i].c-a[j].c;
							}
					}
			}
			if(t>a[i].r)
			{
					t=a[i].r;
					tt=i;
			}
	}
	for(int i=1;i<=n;i++)
	{
		if(i<tt)
		{
			a[i].h+=a[tt].c-a[i].c;
		}
		else if(i>tt)
		{
			a[i].h+=a[i].c-a[tt].c;
		}
	}
	int l=tt-1,r=tt+1;
	while(m>=0)
	{
			if(l==0&&r==n)
			{
				break;
			}
			if(a[l].h<a[r].h)
			{
				if(l>=0)
				{
					m-=a[l].h;
					if(m>0)
					{
					
						l--;
						s++;
					}
					else
					{
						break;
					}
				}
				else
				{
					a[l].h=0x3f3f3f3f;
				}
			}
			else if(a[l].h>=a[r].h)
			{
				if(r<=n)
				{
					m-=a[r].h;
					if(m>0)
					{
					
						r++;
						s++;
					}	
					else
					{
						break;
					}
				}
				else
				{
					a[r].h=0x3f3f3f3f;
				}
			}
	}
	cout<<s;
	return 0;
}
/*

*/
