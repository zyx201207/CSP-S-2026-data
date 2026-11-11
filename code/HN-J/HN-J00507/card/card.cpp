#include<bits/stdc++.h>
using namespace std;
#define lt (u<<1)
#define rt (u<<1|1)
#define mid (l+r>>1)
int lazy[4000005],dp[1000005],la[1000005],n,m,a[1000005];
void pushdown(int u)
{
	lazy[lt]+=lazy[u];
	lazy[rt]+=lazy[u];
	lazy[u]=0;
}
void modify(int u,int l,int r,int ql,int qr,int val)
{
	if(ql<=l&&qr>=r)
	{
		lazy[u]+=val;
		return ;
	}
	pushdown(u);
	if(ql<=mid)
	{
		modify(lt,l,mid,ql,qr,val);
	}
	if(qr>mid)
	{
		modify(rt,mid+1,r,ql,qr,val);
	}
}
int query(int u,int l,int r,int x)
{
	if(l==r)
	{
		return lazy[u];
	}
	pushdown(u);
	if(x<=mid)
	{
		return query(lt,l,mid,x);
	}
	else
	{
		return query(rt,mid+1,r,x);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m; 
	int len=0,f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]&&i>=2)
		{
			f=1;
		}
		if(a[i]!=a[i-1]&&i>=2)
		{
			len++;
		}
	 } 
	 if(len>=5000)
	 {
	 	f=1;
	 }
	 if(n<=5000||f==0)
	 {
	 	for(int i=1;i<=n;i++)
	 	{
	 		vector<int>v;
	 		for(int j=1;j<=n;j++)
	 		{
	 			if(la[a[j]]!=0)
	 			{
	 				while(v.back()!=a[j])
	 				{
	 					v.pop_back();
					 }
				 }
				 else
				{
					v.push_back(a[j]);
					la[a[j]]=1;
				}
			 }
			while(v.size())
			{
				dp[v.back()]++;
				la[v.back()]=0;
				v.pop_back();
			}
		 }
		 for(int i=1;i<=m;i++)
		 {
		 	cout<<dp[i]<<' ';
		 }
		 return 0;
	 }
	int last1=0,lastval=0;
	 for(int i=1;i<=n;i++)
	 {
	 	if(la[a[i]]!=0)
		{
			int laz=query(1,1,n,la[a[i]]);
			if(la[a[i]]<last1)
			{
				modify(1,1,n,la[a[i]]+1,i-1,max(0,dp[a[i]]-laz-lastval));
			} 
			else
			{
				modify(1,1,n,la[a[i]]+1,i-1,dp[a[i]]-laz);
			}
		}
		la[a[i]]=i;
		dp[a[i]]=i;
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	cout<<dp[i]-query(1,1,n,la[i])<<' ';
	 }
	return 0;
}
//读了四分钟题目XwX 
//不是这真是J吗，为什么T4一点思路都没有，只会写模拟（话说模拟好像也是一种思路）。 
//有思路了似乎是DP，但好像又不是，不知道在干什么（10:47）。
//10:54 DP超时了 
//11:46 线段树+DP假了，写暴力。 
