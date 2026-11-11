//GZ-S00012 观山湖区铭苑中学 吴金源 
#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int sum[2000005];
int ccc;
int n,d;
bool sjdy(int u,int v)
{
	int c=0;
	for(int i=u;i<=v;i++)
	{
		for(int j=i;j<=v;j++)
		{
			if(j>d)
				break;
			c++;
		}
		sum[++ccc]=c;
		c=0;
	}
	sort(sum+1,sum+ccc+1);
	if(sum[1]==sum[2] && sum[2]!=sum[3])
		return 1;
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ccc=0;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(sjdy(i,j))
					ans++;
		cout<<ans<<endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}
