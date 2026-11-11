#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q;
long long int w[1005],ka[1005][1005],kt[1005][1005],x,y,t[1000],k[105];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=c;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>ka[c][j]>>kt[c][j];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int t1=0;
		t1+=w[x];
		int minn=100,now,goo;
		for(int j=1;j<=m;j++)
		{
			for(int z=1;z<=k[j];z++)
			{
				if(x==ka[j][z]&&kt[j][z]<minn)
				{
					minn=kt[j][z];
					now=j;
				}
			}
		}
		t1+=minn;
		minn=100;
		for(int j=1;j<=k[now];j++)
		{
			if(ka[now][j]==y)
			{
				t1+=kt[now][j];
				t1+=w[y];
				t[i]=t1;
				continue;
			}
		}
		for(int j=1;j<=m;j++)
			for(int z=1;z<=k[j];z++)
				if(y==ka[j][z])goo=j;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<t[i];
	}
}
