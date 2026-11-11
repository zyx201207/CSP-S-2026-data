#include <bits/stdc++.h>
using namespace std;
int a[500002],b2[300002],p[500001];

void fun1(int x,int y)
{
	for(int i = 1;i<=x;i++)
	{
		p[i]=0;
	}
	p[1]=y;
}

int main()
{
	//freopen("card.in",'w',stdin());
	//freopen("card.out",'r',stdout());
	
	int m,n;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		int t = 0,b1[300002];
		fun1(n,0);
		for(int j = i;j<=n;j++)
		{
			if(b1[a[j]]!=0)
			{
				fun1(t,a[j]);
				for(int k = 1;k<=m;k++)
				{
					b1[k]=0;
				}
				b1[a[j]]=1;
				t=1;
			}
			else
			{
				t++;
				p[t]=a[j];
				b1[a[j]]++;
			}
		}
		for(int j = 1;j<=t;j++)
		{
			b2[p[j]]++;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << b2[i] << " ";
	}
	return 0;
}
