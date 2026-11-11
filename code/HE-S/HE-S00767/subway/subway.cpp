#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=N*N/2; 
int c,n,m,d,q;
int w[M];
vector<pair<int,int>>g[N];
long long ans;
int min1=1e9+1,min2=1e9+1;
long long min3=2e9+1;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		long long sum=0;
		while(k)
		{
			--k;
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
			if(a==1)min1=min(min1,t);
			if(a==2)min2=min(min2,t);
			sum+=t; 
		}min3=min(min3,sum);
	}
	while(q--)
	{
		ans=0;
		int x,y;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		ans+=min(min1*2*1LL+min2*2*1LL,min3);
		cout<<ans<<"\n";
	}
	return 0;
}
