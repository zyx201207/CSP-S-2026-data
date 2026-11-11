#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
long long a[N],d;
int b[N],c[N],cmt;
vector<int> v1[N],v2[N];
pii p[N];
bool vis[N];
void back(int x)
{
	cmt+=1-vis[x];
	vis[x]=true;
	for(int i=0;i<v1[x].size();i++) back(v1[x][i]);
}
void forw(int x)
{
	cmt+=1-vis[x];
	vis[x]=true;
	for(int i=0;i<v2[x].size();i++) forw(v2[x][i]);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,t;
	cin >> cc >> t;
	while(t--)
	{
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		memset(p,0,sizeof(p));
		int n,now=1,cnt=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			while(a[now]-a[i]<=d&&now<=n) now++;
			now--;
			b[i]=now;
		}
		for(int i=n;i>=1;i--)
		{
			while(a[i]-a[now]<=d&&now>=1) now--;
			now++;
			c[i]=now;
		}
		for(int i=1;i<=n;i++)
		{
			while((b[i]>c[now]&&now<n)||now<=i) now++;
			if(b[i]==c[now])
			{
				v1[i].push_back(now);
				v2[now].push_back(i);
			}
		}
		now=1;
		for(int i=1;i<=n;i++)
		{
			while((b[i]-c[now]>1&&now<n)||now<=i) now++;
			if(b[i]-c[now]==1) p[++cnt]={i,now};
		}
		long long ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int t1=p[i].first,t2=p[i].second;
			forw(t1);
			int t3=cmt;
			back(t2);
			int t4=cmt-t3;
			cmt=0;
			memset(vis,0,sizeof(vis));
			ans+=t3*t4;
		}
		cout << ans << endl;
	}
	return 0;
}
