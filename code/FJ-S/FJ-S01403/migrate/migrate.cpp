#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 2e6+5;
ll pos[MAXN] = {0};
int next[MAXN] = {0};
set<pair<ll,int> > st;

pair<int,ll> dp[MAXN];

ll read()
{
	ll res = 0;
	bool f = 0;
	char tc = getchar();
	while(tc < '0' || tc > '9')
	{
		if(tc == '-') f = 1;
		tc = getchar();
	}
	while(tc >= '0' && tc <= '9')
	{
		res = (res<<1)+(res<<3)+(tc^48);
		tc = getchar();
	}
	return f?-res:res;
}

int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c = read(),t = read();
	while(t--)
	{
		int n = read();
		ll d = read();
		for(int i = 0;i < n;i++) 
		{
			pos[i] = read();
			st.insert(make_pair(pos[i],i));
		}
		
		for(int i = 0;i < n;i++)
			next[i] = (*(--st.upper_bound(make_pair(pos[i]+d,INT_MAX)))).se;
		
		ll cnt = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = i;j < n;j++) dp[j] = make_pair(INT_MAX,0);
			priority_queue<int,vector<int>,greater<int> > q;
			q.push(i);
			dp[i] = make_pair(0,1);
			while(q.size()) 
			{
				int np = q.top();
				q.pop();
				while(q.top() == np && q.size()) q.pop();
				if(dp[np].se == 2) cnt++;
				//cout<<np<<" "<<dp[np].fi<<" "<<dp[np].se<<endl;
				for(int j = next[np];j >= max(next[np]-3,np+1);j--)
				{
					q.push(j);
					if(dp[j].fi > dp[np].fi+1)
					{
						dp[j].fi = dp[np].fi+1;
						dp[j].se = dp[np].se;
					}
					else if(dp[j].fi == dp[np].fi+1)
						dp[j].se += dp[np].se;
					//cout<<j<<"/ /"<<dp[j].fi<<"/ /"<<dp[j].se<<endl;
				}
			}
			
		}
		
		cout<<cnt<<endl;
		st.clear();
	}
	
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
