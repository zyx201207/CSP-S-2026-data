#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ull unsigned long long
#define i128 __int128
#define pii pair<int,int>
#define inf 1000000000
#define infl 1000000000000000000ll
#define ls (p<<1)
#define rd (p<<1|1)
const int N=2e6+5;
const int M=1e7+5;
int n,d,a[N],dis[N];
vector<int> P[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			dis[i]=0;
			for(int j=0;j<=n;j++) P[j].clear();
			P[0].push_back(i);
			int lst=i;
			for(int j=i+1;j<=n;j++)
			{
				if(dis[j-1]==infl)
				{
					dis[j]=infl;
					continue;
				}
				while(a[j]-a[lst]>d) lst++;
				if(lst==j) dis[j]=infl;
				else dis[j]=dis[lst]+1;
				if(dis[j]!=infl) P[dis[j]].push_back(j);
			}
			for(int j=i+1;j<=n;j++)
			{
				if(dis[j]==infl) break;
				int x=0,y=0,z=0;
				if(P[dis[j]-1].size()) x=P[dis[j]-1][P[dis[j]-1].size()-1];
				if(P[dis[j]-1].size()>1) y=P[dis[j]-1][P[dis[j]-1].size()-2];
				if(P[dis[j]-1].size()>2) z=P[dis[j]-1][P[dis[j]-1].size()-3];
				// cout<<j<<' '<<x<<' '<<y<<' '<<z<<endl;
				if(y&&a[j]-a[y]<=d)
				{
					if(z&&a[j]-a[z]<=d) continue;
					ans++;
				}  
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/