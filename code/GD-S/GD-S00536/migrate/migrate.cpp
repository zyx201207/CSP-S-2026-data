//code by ElderFour
//problem:migrate
#include<bits/stdc++.h>
using namespace std;
const long long N=2000010,INF=1e18;
long long n,T,m,c,pos[N],g[N],answer,DP[N],f[N];
struct Range
{
	long long l,r;
}a[N];
long long tree[5010*4];
//map<long long,long long>mp;
long long mp[5010][5010];
void add(long long l,long long r,long long no,long long x,long long k)
{
	if(l==r)
	{
		tree[no]=k;
		return ;
	}
	long long mid=l+r>>1;
	if(mid>=x)add(l,mid,no<<1,x,k);
	else add(mid+1,r,no<<1|1,x,k);
	tree[no]=min(tree[no<<1],tree[no<<1|1]);
	return;
}
long long query(long long l,long long r,long long no,long long nl,long long nr)
{
	if(nl>nr)return INF;
	if(nl<=l&&r<=nr)
	{
		return tree[no];
	}
	long long mid=l+r>>1,answer=INF;
	if(mid>=nl)answer=min(answer,query(l,mid,no<<1,nl,nr));
	if(mid+1<=nr)answer=min(answer,query(mid+1,r,no<<1|1,nl,nr));
	return answer;
}
void clear(long long l,long long r,long long no)
{
	tree[no]=0;
	if(l==r)return;
	long long mid=l+r>>1;
	clear(l,mid,no<<1);
	clear(mid+1,r,no<<1|1);
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		answer=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>pos[i];
		}
		for(int i=1;i<=n;i++)
		{
			long long l=0,r=i,mid;
			while(l+1<r)
			{
				mid=(l+r)>>1;
				if(pos[mid]>=pos[i]-m)r=mid;
				else l=mid;
			}
			a[i].l=r;
			a[i].r=i; 
		}
//		for(int i=1;i<=n;i++)cout<<a[i].l<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			clear(1,n,1);
			for(int j=1;j<i;j++)add(1,n,1,j,INF),DP[j]=INF;
			DP[i]=0;
			f[i]=1;
			add(1,n,1,i,0);
//			cout<<query(1,n,1,1,1)<<'\n';
			for(int j=i+1;j<=n;j++)
			{
				DP[j]=query(1,n,1,a[j].l,j-1)+1;
//				cout<<DP[j]<<' ';
//				cout<<a[j].l<<':'<<j-1<<":"<<query(1,n,1,a[j].l,j-1)<<' ';
//				answer+=(DP[j]==2);
				add(1,n,1,j,DP[j]);
//				cout<<DP[j]<<' ';
			}
//			cout<<'\n';
			for(int k=0;k<=n;k++)mp[i][k]=0;
			mp[i][0]=1;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=0;k<=n;k++)mp[j][k]=mp[j-1][k];
				if(DP[j]<=5000)mp[j][DP[j]]++;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(DP[j]-1<=5000&&DP[j]-1>=0)f[j]=mp[j-1][DP[j]-1]-mp[a[j].l-1][DP[j]-1];
				answer+=(f[j]==2);
//				cout<<f[j]<<' ';
			}
//			cout<<'\n';
		}
		cout<<answer<<'\n';
	}
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6 
*/
