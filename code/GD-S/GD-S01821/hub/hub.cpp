#include<bits/stdc++.h>
using namespace std;
long long csd,qt,n,m,k,la[1010],ne[1010],f[1010],d[1010],dd[1010],ccnt;
pair<long long,long long> aa[1010];
vector<long long> v[1010];
void dfs(long long x,long long y,long long z)
{
	for(long long i:v[x])
	{
		if(i==y) continue;
		dfs(i,x,z);
		if(ne[i] || i==z) ne[x]=i;
	}
	if(ne[x]) la[ne[x]]=x;
}
void dfs1(long long x,long long y,long long de)
{
	d[x]=dd[x]=de;
	for(long long i:v[x])
	{
		if(i==y) continue;
		dfs1(i,x,de+1);
		dd[x]=max(dd[x],dd[i]);
		f[x]+=f[i];
	}
	if(dd[x]-d[x]>=m) f[x]++;
}
bool ff()
{
	for(long long s=1;s<=n;s++)
	{
		for(long long t=s+1;t<=n;t++)
		{
			for(long long i=1;i<=n;i++) ne[i]=la[i]=f[i]=d[i]=dd[i]=0;
			dfs(s,0,t);
			long long cnt=0,cc=0;
			ccnt=0;
			for(long long now=s;;now=ne[now])
			{
				cnt++;
				bool mu=false;
				for(long long i:v[now])
				{
					if(i!=ne[now] && i!=la[now])
					{
						dfs1(i,now,1);
						cnt+=f[i];
						dd[now]=max(dd[now],dd[i]);
					}
				}
				cc++;
				if(m>=dd[now]) aa[++ccnt]={cc-(m-dd[now]),cc+(m-dd[now])};
				else aa[++ccnt]={cc,cc};
				if(now==t) break;
			}
			long long minn1=cnt;
			sort(aa+1,aa+1+ccnt);
			for(long long i=ccnt,minn=cc+1;i>=1;i--)
			{
				aa[i].first=max(aa[i].first,1ll);
				aa[i].second=min(aa[i].second,cc);
				minn1=min(minn1,cnt-min(minn-aa[i].first-1,m*2));
				minn=min(minn,aa[i].second);
			}
			if(minn1<=k) return true;
		}
	}
	return false;
}
void solve()
{
	cin>>n>>k;
	for(long long i=1;i<=n;i++) v[i].clear();
	for(long long i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	long long l=1,r=n;
	while(l<r)
	{
		m=(l+r)/2;
		if(ff()) r=m;
		else l=m+1;
	}
	cout<<l<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>csd>>qt;
	while(qt--) solve();
	return 0;
}
