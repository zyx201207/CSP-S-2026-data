/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int c,t;
int n;
long long d;
const int N=1e6+10;
long long x[N];
vector<int>a[N];
int ret[N];
struct node{
	int id;
	int x;
	bool operator < (const node &cmp) const{
		return cmp.x<x;
	}
};
priority_queue<node>q;
int cnt[N];
int in[N];
void init(int k)
{
	for(int i=k;i<=n;i++)
	{
		ret[i]=INT_MAX;
		cnt[i]=0;
	}	
	for(int i=k;i<=n;i++)
	{
		in[i]=0;
	}
	ret[k]=0;
}
vector<int>b[N];
int dj(int o)
{
	init(o);
	node frt={o,0};
	q.push(frt);
	while(!q.empty())
	{
		node g=q.top();
		q.pop();
		int u=g.id;
		int x_=g.x;
		if(ret[u]<x_) continue;
		for(auto v:a[u])
		{
			if(ret[v]>ret[u]+1)
			{
				ret[v]=ret[u]+1;
				q.push({v,ret[v]});
			}
		}
	}
	for(int i=o;i<=n;i++)
	{
		b[i].clear();
	}
//	for(int i=o;i<=n;i++)
//	{
//		cout<<ret[i]<<" ";
//	}
//	cout<<endl;
	for(int i=o;i<=n;i++)
	{
		for(auto v:a[i])
		{
			if(ret[v]==ret[i]+1)
			{
				b[i].push_back(v);
//				cout<<i<<" "<<v<<endl;
				in[v]++;
			}
		}
	}
	queue<int>p_;
	for(int i=o;i<=n;i++)
	{
		if(in[i]==0)
		{
			p_.push(i);
			cnt[i]=1;
//			cout<<i<<" ";
		}
	}
//	cout<<endl;
	while(!p_.empty())
	{
		int kl=p_.front();
		p_.pop();
		for(auto v:b[kl])
		{
			cnt[v]+=cnt[kl];
			in[v]--;
			if(in[v]==0)
			{
				p_.push(v);
			}
		}
	}
	int ans=0;
	for(int i=o;i<=n;i++)
	{
		if(cnt[i]==2)
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		n=read();
		d=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
			a[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					a[i].push_back(j);
//					cout<<i<<" "<<j<<endl;
				}
			}
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			ret+=dj(i);
		}
		printf("%d\n",ret);
	}
	return 0;
}
