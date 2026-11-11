#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
struct mp
{
	long long v,w;
};
struct node
{
	long long id,dis;
	bool operator < (const node other)const{
		return dis>other.dis;
	}
};
vector <mp> mapp[2000005];
priority_queue <node> q;
long long dis_1[2000005];
long long dis_2[2000005];
long long dis_3[2000005];
long long book[2000005];
void dijsktra(long long x)
{
	memset(book,0,sizeof book);
	memset(dis_1,0x3f,sizeof dis_1);
	memset(dis_2,0x3f,sizeof dis_2);
	memset(dis_3,0x3f,sizeof dis_3);
	while(!q.empty()) q.pop();
	node t;
	t.id=x,t.dis=0;
	dis_1[x]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		long long k=t.id;
		if(book[k]==1) continue;
		book[k]=1;
		for(long long i=0;i<(int)mapp[k].size();i++)
		{
			if(mapp[k][i].v<k) continue;
			long long v=mapp[k][i].v,w=mapp[k][i].w;
			if(dis_1[v]>=dis_1[k]+w)
			{
				dis_3[v]=dis_2[v];
				dis_2[v]=dis_1[v];
				dis_1[v]=dis_1[k]+w;
				node r;
				r.id=v,r.dis=dis_1[v];
				q.push(r);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		for(long long i=1;i<=n;i++)
		{
			mapp[i].clear();
		}
		for(long long i=1;i<n;i++)
		{
			mp l,r;
			l.v=i+1,l.w=1;
			r.v=i,r.w=1;
			mapp[i].push_back(l);
			mapp[i+1].push_back(r);
		}
		for(long long i=1;i<n-1;i++)
		{
			for(long long j=i+2;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					mp l,r;
					l.v=j,l.w=1;
					r.v=i,r.w=1;
					mapp[i].push_back(l);
					mapp[j].push_back(r);
				}
				else break;
			}
		}
		long long ans=0;
		for(long long i=1;i<n-1;i++)
		{
			dijsktra(i);
			for(long long j=i+1;j<=n;j++)
			{
				if((dis_1[j]==dis_2[j])&&(dis_2[j]<dis_3[j])&&(dis_1[j]<dis_3[j])) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
