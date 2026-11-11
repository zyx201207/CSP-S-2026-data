#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>g;
vector<int>llen,rlen;
bool visl[2000010],visr[2000010];
void gor(int u)
{
	rlen[u]=1;
	for(auto v:g[u])
		if(!visr[v])
			visr[v]=true,gor(v),rlen[u]+=rlen[v];
}
void gol(int u)
{
	llen[u]=1;
	for(auto v:g[u])
		if(!visl[v])
			visl[v]=true,gol(v),llen[u]+=llen[v];
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ifstream cin("migrate.in",ios::in);
//	ofstream cout("migrate.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,T;
	cin>>c>>T;
	while(T--)
	{
		long long n,d;
		cin>>n>>d;
		vector<int>a(n+1);
		for(long long i=1,x;i<=n;i++) cin>>x,a[i]=x;
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		vector<int>r(n+1,0),l(n+1,0);
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<n&&a[j+1]-a[i]<=d) j++;
			r[i]=j;
		}
		for(int i=n,j=n;i>=1;i--)
		{
			while(j>1&&a[i]-a[j-1]<=d) j--;
			l[i]=j;
		}
//		for(int i=1;i<=n;i++)
//			cout<<r[i]<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//			cout<<l[i]<<" ";
//		cout<<endl;
		g.clear();
		g.resize(n+1);
		llen.clear();
		rlen.clear();
		llen.resize(n+1,0);
		rlen.resize(n+1,0);
		for(int i=1;i<=n;i++) visl[i]=visr[i]=false;
		for(int i=1;i<=n;i++)
			if(r[i]>i&&l[r[i]]==i)
				g[i].push_back(r[i]),
				g[r[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(!visr[i])
				visr[i]=true,gor(i);
		for(int i=n;i>=1;i--)
			if(!visl[i])
				visl[i]=true,gol(i);
		//add up all the rightlens that l_j=i as sum_i
		vector<int>sum(n+1,0);
		vector<int>sum1(n+1,0);
		for(int i=1;i<=n;i++)
			if(l[i]<i-1)
				if(r[l[i]+1]==i)
					sum[l[i]]+=rlen[i];
				else sum[l[i]]++;
		int res=0;
		for(int i=1;i<=n;i++)
			if(r[i]>i+1)
			{
				res+=(l[r[i]-1]<i?1:llen[i])*sum[r[i]-1];
//				cout<<(l[r[i]-1]<i?1:llen[i])<<" "<<sum[r[i]-1]<<endl;
			}
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//				if(r[i]>i&&l[j]<j&&r[i]==l[j]+1&&r[i]!=j&&l[j]!=i)
//				{
////					cout<<endl;
////					cout<<i<<" "<<j<<endl;
//					int lc,rc;
//					if(r[r[i]]==j) rc=rlen[j];
//					else rc=1;
//					if(l[l[j]]==i) lc=llen[i];
//					else lc=1;
////					cout<<lc<<" "<<rc<<endl;
//					res+=lc*rc;
//				}
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//				if(r[i]>i&&l[j]<j&&r[i]==l[j]+1&&l[j]!=i&&r[i]!=j)
//					cout<<i<<" "<<j<<" "<<llen[i]<<" "<<rlen[j]<<endl,res+=llen[i]*rlen[j];
//		int xxxxx=0;
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//			{
//				int now=i;
//				vector<int>path1;
//				path1.push_back(now);
////				cout<<now<<" ";
//				while(r[now]<j) now=r[now]path1.push_back(now);
////				cout<<j<<endl;
//				now=j;
//				path1.push_back(j);
//				vector<int>path;
//				path.push_back(now);
//				while(l[now]>i) now=l[now],path.push_back(now);
//				path.push_back(i);
//				reverse(path.begin(),path.end());
////				for(auto it:path) cout<<it<<" ";
//				int flag=0;
//				for(int i=0,len=path.size();i<len;i++)
//					if(path[i]!=path1[i]) flag++;
//				if(flag==1) xxxxx++;
//			}
		long long xxx=res;
		cout<<xxx<<endl;
	}
	return 0;
}
/*
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(r[i]>i&&l[j]<j&&r[i]==l[j]+1&&r[r[i]]==j&&l[l[j]]==i)
cout<<i<<" "<<j<<" "<<llen[i]<<" "<<rlen[j]<<endl,res+=llen[i]*rlen[j];
*/
