#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,a[N];
int ans;
int val[2],cnt[2];
queue<pair<int,int>>q[2];
bool ckA()
{
	if(c==11||c==12)return 1;
	int del=a[2]-a[1];
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=del)
			return 0;
	return 1;
}
void spA()
{
	int st=d/(a[2]-a[1]);
	if(st<2)
	{cout<<"0\n";return ;}
	ans=0;
	for(int i=1;i<=n;i++)
		if(i+2*st-1<=n)
			ans++;
	cout<<ans<<'\n';
	return ;
}
bool ckB()
{
	if(c==13||c==14)return 1;
	for(int i=1;i<=n;i++)
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
			return 1;
	return 0;
}
void spB()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		int res=i;
		for(int l=i,r=n;l<=r;)
		{
			int mid=(l+r)/2;
			if(a[mid]-a[i]<=d)
				res=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=(n-res);
	}
	cout<<ans<<'\n';
	return ;
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
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(ckA()){spA();continue;}
		if(ckB()){spB();continue;}
		ans=0;
		for(int l=1;l<=n;l++)
		{
			val[0]=val[1]=-1;
			cnt[0]=cnt[1]=0;
			q[0]={},q[1]={};
			int hd=0;
			val[hd]=0,cnt[hd]=1;
			q[hd].push({l,1});
			for(int r=l+1;r<=n;r++)
			{
				for(;cnt[hd]&&a[r]-a[q[hd].front().first]>d;)
				{
					cnt[hd]-=q[hd].front().second;
					q[hd].pop();
				}
				if(!cnt[hd])val[hd]=-1,hd^=1;
				for(;cnt[hd]&&a[r]-a[q[hd].front().first]>d;)
				{
					cnt[hd]-=q[hd].front().second;
					q[hd].pop();
				}
				if(!cnt[hd])val[hd]=-1,hd^=1;
				if(val[hd]==-1)break;
				int nv=val[hd]+1,nc=cnt[hd];
				if(nc==2)ans++;
				if(val[hd^1]<0)val[hd^1]=nv;
				cnt[hd^1]+=nc;
				q[hd^1].push({r,nc});
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
题意：

若干个点有坐标，两点互相可达，则dis(a[x]-a[y])<=d
从点l到点r的最短路有两条，找所有的[l,r]

恰好只有两条，还挺严格 

感觉恰好只能有2步？
同一起点的可行终点：第一步跳max和max-1，第二步都跳max之间的点？ 
不太对

只会在(一个大跳，两个大跳]之间找

结论假了？

不算很假，前前后后加几步差不多 

不会了，拼n^2吧  
*/
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=2e6+5;
//int c,T,n,d,a[N];
//int L[N],R[N];
//int pre[N],suf[N];
//int ans;
//signed main()
//{
//	freopen("migrate3.in","r",stdin);
////	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	cin>>c>>T;
//	while(T--)
//	{
//		cin>>n>>d;
//		cout<<"nd "<<n<<' '<<d<<'\n';
//		for(int i=1;i<=n;i++)
//			cin>>a[i];
//		for(int i=1;i<=n;i++)
//		{
//			for(int l=1,r=i;l<=r;)
//			{
//				int mid=(l+r)/2;
//				if(a[i]-a[mid]<=d)
//					L[i]=mid,r=mid-1;
//				else l=mid+1;
//			}
//			for(int l=i,r=n;l<=r;)
//			{
//				int mid=(l+r)/2;
//				if(a[mid]-a[i]<=d)
//					R[i]=mid,l=mid+1;
//				else r=mid-1;
//			}
////			cout<<L[i]<<' '<<i<<' '<<R[i]<<'\n';
//		}
//		pre[1]=1;
//		for(int i=2;i<=n;i++)
//		{
//			if(R[i-1]==i)
//				pre[i]=pre[i-1]+1;
//			else pre[i]=1;
//		}
//		suf[n]=1;
//		for(int i=n-1;i>=1;i--)
//		{
//			if(R[i]==i+1)
//				suf[i]=suf[i+1]+1;
//			else suf[i]=1;
//		}
//		for(int i=1;i<=n;i++)
//			cout<<pre[i]<<" \n"[i==n];
//		for(int i=1;i<=n;i++)
//			cout<<suf[i]<<" \n"[i==n];
//		ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			int fst=R[i],scd=R[fst-1];
//			if(fst-i<2)continue;//不够
//			if(fst==scd)continue;//太近了 
//			cout<<i<<' '<<scd<<'\n';
//			if(fst-i==2)//刚刚好 
//			{
//				ans+=pre[i]*(scd-1-fst+suf[scd]);
//			}
//			else ans+=pre[i]*(scd-1-R[(fst-2)]+suf[scd]);
//		}
//		cout<<ans<<'\n';
//	}
//	return 0;
//}
