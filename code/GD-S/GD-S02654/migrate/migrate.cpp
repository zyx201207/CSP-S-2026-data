#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],nxt[2000005][2],pre[2000005],dp[2000005],dp2[2000005];
const int maxd=114514114514114514;//1e17
int findnxt(int x)
{
	int l=x-1,r=n+1,ans=0;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<=a[x]+d)ans=max(ans,mid),l=mid;
		else r=mid;
	}
	return ans;
}
int findpre(int x)
{
	int l=0,r=x+1,ans=maxd;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(a[mid]>=a[x]-d)ans=min(ans,mid),r=mid;
		else l=mid;
	}
	return ans;
}
bool one(int i,int v)
{
	while(i<v)
	{
		int j=findnxt(i);
		int k=findnxt(j);
		int l=findpre(k);
		if(j==l)i=k;
		else return 0;
	}
	return 1;
}
int minn(int i,int v)
{
	int cnt=0;
	while(i<v)
		cnt++,i=findnxt(i);
	return cnt;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),
			dp[i]=dp2[i]=nxt[i][1]=0,nxt[i][0]=n+1;
		for(int i=1;i<=n;i++)
		{
			dp[i]+=i-(findpre(findpre(i)));
			//cout<<"---"<<pre[i]<<"---"<<i-(findpre(findpre(i))-1)<<endl;
			//if(findpre(i)+1<i)dp[i]-=(findpre(i)-findpre(findpre(i)+1));
			int j=findnxt(i);
			int k=findnxt(j);
			if(i==j||i==k||j==k)continue;
			int l=findpre(k);
			if(j==l)
			{
				nxt[i][0]=k,pre[k]=i;//,cout<<i<<" "<<k<<":1\n";
				int m=findnxt(j-1);
				if(j<m&&m<k)
				{
					int l2=findpre(m);
					if(i<l2&&j==l2+1)nxt[i][1]=m;//,cout<<i<<" "<<m<<":2\n";
				}
			}
			else if(j==l+1)nxt[i][1]=k;//,cout<<i<<" "<<k<<":2\n";
		}
//		for(int i=n;i>=1;i--)
//		{
//			dp2[i]+=findnxt(i)-i+1;
//			if(nxt[i][0]&&findnxt(i)-1>i)
//				dp2[i]+=nxt[i][0]-findnxt(findnxt(i)-1)-1;
//			if(pre[i])dp2[pre[i]]+=dp2[i];
//		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!nxt[i][1])continue;
			int j=nxt[i][1];
			for(int a=max(1ll,pre[i]);a<=i;a++)
				for(int b=j;b<=min(nxt[i][0],n);b++)
					if(one(a,i)&&one(j,b)&&
					minn(a,b)==minn(a,i)+minn(j,b)+2)
					//cout<<"---"<<a<<" "<<b<<endl,
					ans++;
		}
		printf("%lld\n",ans);
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
