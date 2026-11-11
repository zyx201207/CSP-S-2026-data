//GZ-S00027 ½ªÔ£Î°
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int n,k;
vector<int> a[1000005];
int s;
bool b[1000005];
int ans=INT_MAX;
int anss;
void aaa(int x,int f)
{
	if(b[f]==0&&b[x]==1)
	{
		s++;
	}
	for(int i:a[x])
	{
		if(i==f) continue;
		aaa(i,x);
	}
} 
bool inq[1005];
int aa(int x)
{
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(x);
	inq[x]=1;
	int s=0;
	while(q.size())
	{
		int l=q.size();
		while(l--)
		{
			int k=q.front();
			q.pop();
			if(b[k]) return s;
			for(int i:a[k])
			{
				if(inq[i]) continue;
				q.push(i);
				inq[i]=1;
			}
		}
		s++;
	}
	return s;
}
void ss(int x,int kk)
{
	if(x==n+1)
	{
		if(kk!=k) return ;
		s=0;
		aaa(1,0);
		if(s>2) return ;
		anss=0;
		for(int i=1;i<=n;i++)
		{
			anss=max(anss,aa(i));
		}
		ans=min(anss,ans);
		return ;
	}
	if(kk>k||n-x+1+kk<k) return ;
	//1
	b[x]=1;
	ss(x+1,kk+1);
	b[x]=0;
	ss(x+1,kk);
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=INT_MAX;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++)
		{
			int uu,vv;
			scanf("%lld%lld",&uu,&vv);
			a[uu].push_back(vv);
			a[vv].push_back(uu);
		}
		ss(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}

