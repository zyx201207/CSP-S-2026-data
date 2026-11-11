#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m;
vector<int> v[N];
int Fa[N];
void dfs1(int x,int fa)
{
	Fa[x]=fa;
	for(int y:v[x]) if(y!=fa)
	{
		dfs1(y,x);
	}
}
int mid;
int ans1[N],ans11[N];
int f[N],DEP[N];
int ans2[N],ans22[N];
int dfs2(int x,int fa)
{
	f[x]=0;
	int ans=0;
	for(int y:v[x]) if(y!=fa)
	{
		ans+=dfs2(y,x);
		f[x]=max(f[x],f[y]+1);
	}
	if(f[x]>=mid) ans++;
	return ans;
}
void dfs3(int x,int fa,int dep)
{
	DEP[x]=dep;
	f[x]=dep;
	for(int y:v[x]) if(y!=fa)
	{
		dfs3(y,x,dep+1);
		f[x]=max(f[x],f[y]);
	}
}
void dfs4(int x,int fa,int ch)
{
	if(Fa[x]==fa) ans22[x]=min(ans22[x],ch);
	else ans2[fa]=min(ans2[fa],ch);
//	cout << x << ' ' << fa << ' ' << f[x] << ' ' << ch << endl;
	if(DEP[x]>mid) return;
//	cout << x << ' ' << fa << ' ' << f[x] << ' ' << ch << endl;
	int ma=0,mma=0;
	for(int y:v[x]) if(y!=fa)
	{
		if(f[y]>ma) mma=ma,ma=f[y];
		else if(f[y]>mma) mma=f[y];
	}
	for(int y:v[x]) if(y!=fa)
	{
		int tmp=ma;
		if(ma==f[y]) tmp=mma;
		if(tmp<=mid) dfs4(y,x,ch);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(m==n)
		{
			printf("0\n");
			continue;
		}
		if(n>4000)
		{
			printf("%d\n",max((n/2-m+4+3)/4,1));
			continue;
		}
		dfs1(1,0);
		int l=0,r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
//			cout << "        " << mid << endl;
			for(int i=2;i<=n;i++) ans2[i]=ans22[i]=n+1;
			for(int i=2;i<=n;i++)
			{
				ans1[i]=max(1,dfs2(i,Fa[i]));
				ans11[i]=max(1,dfs2(Fa[i],i));
//				cout << ans1[i] << ' ' << ans11[i] << endl;
				dfs3(i,Fa[i],1);
				dfs4(i,Fa[i],ans11[i]);
				dfs3(Fa[i],i,1);
				dfs4(Fa[i],i,ans1[i]);
			}
//			cout << endl;
//			for(int i=2;i<=n;i++)
//			{
//				cout << ans2[i] << ' ' << ans22[i] << endl;
//			}
			int ans=n+1;
			for(int i=2;i<=n;i++) ans=min(ans,ans2[i]+ans22[i]);
			if(ans<=m) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
/*
0 1
15 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 9
2 10
3 11
4 12
5 13
6 14
7 15

*/
