#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000006],c,t,sum,minn,y[2000006],dui;
long long zy(long long y)//这个到最远的岛 
{
	int i=y;
	while(x[i]-x[y]<=d&&x[i]-x[y]>=0&&i<=n)
	{
		i++;
	}
	return i-1;
}
void xz(long long i,long long dw,long long v)
{
	if(i==0)
	{
		if(dw==v)
		{
			dui++;
		}
	}
	else// if(x[y[dw]]<x[v])
	{
		for(int j=dw+1;j<=y[dw];j++)
		{
			xz(i-1,j,v);
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			y[i]=zy(i);
		}
		for(int u=1;u<n;u++)
		{
			for(int v=u+1;v<=n;v++)//不同组合 
			{
				int dw=u,minn=0;
				while(x[y[dw]]<x[v])//最少步数 
				{
					if(dw==y[dw])
					{
						break;
					}
					dw=y[dw];
					minn++;
				}
				minn++;
				dui=0;
				xz(minn,u,v);//步数，起点，终点 
				if(dui==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
