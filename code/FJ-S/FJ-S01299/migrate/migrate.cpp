#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T;
ll n,d,a[N],anss=0,f[N],sum[N],cnt[N],sum2[N];
ll dis[N];
vector<int> e[N];
int erfen1(int now)
{
	int l=1,r=now,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[now]-a[mid]<=d) r=mid-1,ans=mid;
		else l=mid+1;		
	}	
	return ans;
}
int erfen2(int now)
{
	int l=1,r=now,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[now]-a[mid]>d) l=mid+1,ans=mid;
		else r=mid-1;		
	}	
	return ans;
}
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	priority_queue<pair<int,int> > pq;
	dis[s]=0;
	cnt[s]=1;
	pq.push({0,s});
	while(pq.size())
	{
		int u=pq.top().second;
		pq.pop();
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				pq.push({-dis[v],v});
			}
			else if(dis[v]==dis[u]+1)
			{
				cnt[v]+=cnt[u];
			}
//			cout << v << " " << cnt[v] << endl;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),e[i].clear();
		anss=0;
		if(c<=6)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d) e[i].push_back(j);
				}
			}
			for(int i=1;i<=n;i++)
			{
				dij(i);
//				cout << i << endl;
				for(int j=i+1;j<=n;j++)
				{
//					cout << cnt[j] <<  " ";
					if(cnt[j]==2) anss++;
				}
//				cout << endl;
			}
			printf("%lld\n",anss);
			continue;
		}
		for(int i=1;i<=n;i++) f[i]=cnt[i]=0;
		a[n+1]=1e18;
		for(int i=1;i<=n;i++)
		{
			int l2=erfen1(i);
			int r2=erfen2(i+1);
//			cout << l2 << " " << r2 << endl;
//			cout << i << " " << cnt[i] << endl; 
			if(l2<i && r2<i && !(l2==1 && r2==1 && a[l2]+d>=a[i+1])) 
			{
//				cout << 1 << endl;
//				cout << i << " " << l2 << " " << cnt[l2] << endl;
				cnt[i]+=1+cnt[l2];
//				cout << cnt[i] << endl;
			}
			int now=erfen1(i);
			if(now==i) continue;
			int l1=erfen1(now);
			int r1=erfen2(now+1);
			if(l1<now && r1<now && !(l1==1 && r1==1 && a[l1]+d>=a[now+1])) f[i]+=(sum[r1]-sum[l1-1]);
//			cout << f[i] << endl;
			if(now<i-1)
			{
//				cout << i<< " " << now << endl;
				f[i]+=cnt[now+1];
			}
//			cout << i<< " " << f[i] << endl;
			anss+=f[i];
			sum[i]=sum[i-1]+f[i];
		}
//		for(int i=1;i<=n;i++) cout << cnt[i] << " ";
//		cout << endl;
		printf("%lld\n",anss);
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

