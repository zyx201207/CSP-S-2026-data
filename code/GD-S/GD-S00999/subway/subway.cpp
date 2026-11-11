#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long c,n,m,d,q,w[500005],f[505],x,y,ans[5005][5005],a1,t1,ans1;
struct node{
	long long t,pre;
}k[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		int a2=0;
		for(int j=1;j<=f[i];j++)
		{
			
			cin>>a1>>t1;
			if(j==1)
			{
				k[a1].pre=0;
				k[a1].t=t1;
				a2=a1;
				continue;
			}
			k[a1].pre=a2;
			k[a1].t=t1;
			a2=a1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i==1)continue;
		ans[k[i].pre][i]=k[i].t+k[k[i].pre].t;
	}
	while(q--)
	{
		cin>>x>>y;
		ans1=0;
		ans1+=w[x]+w[y];
		while(k[y].pre!=0)
		{
			ans1+=ans[k[y].pre][y];
			y=k[y].pre;
		}
		cout<<ans1;
	}
	
}
