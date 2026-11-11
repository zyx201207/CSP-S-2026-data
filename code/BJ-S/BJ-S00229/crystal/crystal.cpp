#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a[500005];
int b[500005];
bool cmp(int x,int y)
{
	return x<y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int minn=1e9;
	int maxn=-1e9;
	bool isteshua=1;
	bool isteshub=1;
	int cha=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(cha==0)
			{
				cha=a[i]-a[i-1];
			}
			if(a[i]-a[i-1]!=cha)
			{
				isteshub=0;
			}
		}
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
		if(a[i]!=i)
		{
			isteshua=0;
		}
		sum+=a[i];

	}
	sum/=n;

	if(isteshua||isteshub)
	{
		int ans=0;
		int i=a[n/2-1];
		for(int j=1;j<=n;j++){b[j]=abs(a[j]-i);}
		sort(b+1,b+n+1,cmp);
		int rp=m;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(rp>=b[j]){rp-=b[j];cnt++;}

		}
		ans=max(ans,cnt);
		i=a[n/2];
		for(int j=1;j<=n;j++){b[j]=abs(a[j]-i);}
		sort(b+1,b+n+1,cmp);
		rp=m;
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(rp>=b[j]){rp-=b[j];cnt++;}

		}
		ans=max(ans,cnt);
		i=a[n/2+1];
		for(int j=1;j<=n;j++){b[j]=abs(a[j]-i);}
		sort(b+1,b+n+1,cmp);
		rp=m;
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(rp>=b[j]){rp-=b[j];cnt++;}

		}
		ans=max(ans,cnt);
		cout<<ans<<endl;
		return 0;

	}
	if(n<=5000&&m<=1000000)
	{
	int ans=0;
	int besti=0;
	for(int i=minn;i<=maxn;i++)//最终的每个数
	{

		for(int j=1;j<=n;j++){b[j]=abs(a[j]-i);}
		sort(b+1,b+n+1,cmp);
		int rp=m;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(rp>=b[j]){rp-=b[j];cnt++;}

		}
		if(cnt>ans)
		{
			ans=cnt;
			besti=i;
		}

	}
	cout<<ans<<endl;
	return 0;
	}
	int ans=0;
	int besti=0;
	//数值逼近法
	for(int i=max(minn,sum-100);i<=min(maxn,sum+100);i++)//最终的每个数
	{

		for(int j=1;j<=n;j++){b[j]=abs(a[j]-i);}
		sort(b+1,b+n+1,cmp);
		int rp=m;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(rp>=b[j]){rp-=b[j];cnt++;}

		}
		ans=max(ans,cnt);

	}
	cout<<ans<<endl;




	return 0;
}