/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll c,t;
ll n,d;
ll x[N];
vector<ll> vec[N];	//储存岛屿i一次飞行可以到的节点 
ll m_ncnt=INF;
ll sum;
ll ans;

inline void dfs(ll k,ll y,ll cnt)	//k,当前岛屿   y,目标岛屿   cnt,飞行次数 
{
	if(k==y)
	{
		if(cnt<m_ncnt)
		{
			m_ncnt=cnt;
			sum=1;
		}
		else if(cnt==m_ncnt) sum++;
		
		return ;
	}
	
	for(auto next:vec[k])
	{
		if(x[next]>x[y]) continue;
		
		dfs(next,y,cnt+1);
	}

	return ;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d) vec[i].push_back(j);
				else break;
			}
		}
		
		for(int start=1;start<=n-3;start++)
		{
			if(vec[start].empty()) continue;
			
			for(int e_d=start+3;e_d<=n;e_d++)
			{
				dfs(start,e_d,0);
				if(sum==2) ans++;
				
				sum=0;
				m_ncnt=INF;
			} 
		}
		
		cout<<ans<<endl;
		
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++) vec[i].clear();
		ans=0;
	}
	
	
	return 0;
} 
