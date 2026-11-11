#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5000000];
int R[5000000];
int f[5000000][3];
int q[5000000]; 
//void sol()
//{
//	int n,dis;
//	scanf("%lld%lld",&n,&dis);
//	for(int i=1;i<=n;i++)
//	{
//		f[i][0]=f[i][1]=0;
//		scanf("%lld",&a[i]);
//	}
//	int r=0;
//	for(int i=1;i<=n;i++)
//	{
//		while(r+1<=n&&a[i]+dis>=a[r+1]) r++;
//		R[i]=r;
//	}
//	R[0]=-1;
//	for(int i=1;i<=n;i++)
//	{
//		if(R[i]<=i) continue;
//		if(R[i-1]==R[i])
//		{
//			f[R[i]][1]+=f[i][0];
//			f[R[i]][0]++;
//		}
//		else
//		{
//			f[R[i]][1]+=f[i][1];
//			f[R[i]][0]+=f[i][0]+1;
//		}
//	}
//	int h=1,t=0;
//	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		while(h<=t&&a[q[h]]+dis<a[i]) h++;
//		if(h<=t)
//		{
//			ans+=f[q[h]][1];
//			cout<<i<<" "<<q[h]<<" "<<f[q[h]][1]<<endl;
//		}
//		if(h+1<=t)
//		{
//			ans+=f[q[h+1]][0];
//			cout<<i<<" "<<q[h+1]<<" "<<f[q[h+1]][0]<<endl;
//		}
//		cout<<i<<" "<<h<<" "<<t<<" "<<q[h]<<" "<<q[h+1]<<endl;
//		ans+=f[i][1];
//		q[++t]=i;
//	}
//	printf("%lld\n",ans);
//}
int d[700000];
int num[700000];
void sol()
{
	int n,dis;
	scanf("%lld%lld",&n,&dis);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int r=0;
	for(int i=1;i<=n;i++)
	{
		while(r+1<=n&&a[i]+dis>=a[r+1]) r++;
		R[i]=r;
	}
	R[0]=-1;
//	cout<<R[1]<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sta=i;
		for(int j=i;j<=n;j++) d[j]=0;
		while(R[sta]!=sta)
		{
			d[R[sta]]=d[sta]+1;
//			if(i==1) cout<<R[sta]<<" "<<d[R[sta]]<<endl;
			sta=R[sta];
		}
		for(int j=n;j>i;j--)
		{
			if(d[j]==0) d[j]=d[j+1];
		}
		int h=1,t=0;
		for(int j=i;j<=n;j++)
		{
			while(h<=t&&a[q[h]]+dis<a[j])
			{
				num[d[q[h]]]--;
				h++;
			}
			if(j>i&&num[d[j]-1]==2)
			{
				ans++;
			}
			q[++t]=j;
			num[d[q[t]]]++;
		}
		while(h<=t) 
		{
			num[d[q[h]]]--;
			h++;
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int fw,T;
	scanf("%lld%lld",&fw,&T);
	while(T--)
	{
		sol();
	}
}
