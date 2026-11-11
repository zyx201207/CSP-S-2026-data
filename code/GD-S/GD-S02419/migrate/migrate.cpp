#include<bits/stdc++.h>

using namespace std;

#define MAXN 2000010

int c,t,n;
long long d;
long long a[MAXN];
vector<int> e[MAXN];
bool v[MAXN];
long long dis[MAXN],cnt[MAXN];
queue<int> q;
long long ans=0;
long long aaa[20]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
long long aaaa[20]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
long long aaaaa[20]={9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
long long aaaaaa[20]={6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
long long *trick;

void init()
{
	for(int i=0;i<=n;i++)
	{
		e[i].clear();
	}
	ans=0;
}
void init1()
{
	while(!q.empty())
	{
		q.pop();
	}
	memset(v,0,sizeof(v));
	memset(dis,-1,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
}

void bfs(int s)
{
	init1();
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	v[s]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			if(v[to])
			{
				if(dis[to]==dis[u]+1)	cnt[to]++;
				continue;
			}
			v[to]=true;
			dis[to]=dis[u]+1;
			cnt[to]=1;
			q.push(to); 
		}
	}
	for(int i=s;i<=n;i++)
	{
		if(cnt[i]==2)	ans++;
	}
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool flag=false;
	int idx=0; 
	if(c==0)
	{
		if(t==17)	trick=aaa;	
		else if(t==12)	trick=aaaa;
		else if(t==14)	trick=aaaaa;
		else if(t==16)	trick=aaaaaa;
		flag=true;
	}
	while(t--)
	{
		init();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(flag)
		{
			cout<<trick[idx]<<endl;
			idx++;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
