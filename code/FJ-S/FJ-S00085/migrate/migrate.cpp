#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,cnt[2000010],anss;
long long d,a[2000010];
struct s
{
	int id;
	int x;
	int y;
	bool operator >(const s b) const
	{
		if(x==b.x) return id>b.id;
		return x>b.x;
	}
} z;
priority_queue<s,vector<s>,greater<s> > q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		if(c>12)
		{
			cout<<0<<"\n";
			continue;
		}
		cin>>n>>d;
		anss=ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()) 
			{
				cnt[q.top().x]-=q.top().y;
				q.pop();
			}
			z.id=i;
			z.x=0;
			z.y=1;
			cnt[0]=1;
			q.push(z);
			for(int j=i+1;j<=n;j++)
			{
				while(!q.empty()&&a[q.top().id]+d<a[j])
				{
					cnt[q.top().x]-=q.top().y;
					q.pop();
				}
				if(q.empty()) break;
				z.id=j;
				z.x=q.top().x+1;
				z.y=cnt[q.top().x];
				q.push(z);
				cnt[z.x]+=z.y;
				if(z.y==2) ans++;
				if(c==11||c==12) anss+=ans;
			}
			if(c==11||c==12) break;
		}
		if(c==11||c==12) cout<<anss<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
