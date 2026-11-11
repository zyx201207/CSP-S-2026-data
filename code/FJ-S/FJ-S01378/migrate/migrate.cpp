#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+9;
int c,T,n,m,a[N],can[N],dis[N],ans,s[N];
int qiu(int x)
{
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int find(int z,int y,int zhi)
{
	int l=z,r=y,ans=y;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(dis[mid]==zhi)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
//	cout<<"??\n";
		ans=0;
		cin>>n>>m;
//		cout<<n<<"??\n";
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
		if(n>5000)
		{
			int g=m/(a[2]-a[1]),ans=0;
			for(int i=1;i<=n;i++)ans+=max((n-i+1)/g-1,0ll);
			cout<<ans<<'\n';
			continue;
		}
	for(int i=1;i<=n;i++)s[i]=0;
	for(int i=1;i<=n;i++)
	{
		int r=i,wei=i,zo=1;
		for(int j=1;j<=n;j++)can[j]=s[j]=0;
		can[i]=1;s[i]=1;
		for(int j=i-1;j;j--)
		{
			can[j]=0;
			while(a[r]-a[j]>m)
			{
				zo-=can[r];
				r--;
			}
			if(j==r)break;
			dis[j]=dis[r]+1;
//			int wei=find(j,r,dis[r]);
			while(dis[r]!=dis[wei]&&wei>j)zo+=can[--wei];
			while(dis[wei-1]==dis[r]&&wei>j)zo+=can[--wei];
//			if(r<=j)break;
//			if(r<=j+1)can[j]=can[r];
//			can[j]=s[wei]-s[r+1];
//			for(int i=max(wei,j+1);i<=r;i++)can[j]+=can[i];
//			cout<<"from:"<<j<<"to:"<<i<<"L:"<<wei<<"R:"<<r<<"zhi:"<<can[j]<<"\n";
			can[j]=zo;
			if(can[j]==2)ans++;
			s[j]=s[j+1]+can[j];
		}
//		for(int j=i-1;j;j--)cout<<can[j]<<' ';cout<<'\n';
	}
	cout<<ans<<'\n';
	}
	return 0;
}
