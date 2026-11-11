#include<bits/stdc++.h>
using namespace std; // fenzhi

#define int long long

int n, m, ans;
vector<int> vec;


int vis[200005]; // The No.(cur) is visited
void dfs(int sum, int k) // k the level  cur the number  sum the count of the numbers
{
	if(k==m)
	{
		ans=max(ans, sum);
		return;
	}
	for(int i=0;i<(int)vec.size();i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(sum&vec[i],k+1);
			vis[i]=0;
		}
	}
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	}
	if(n <= 20) // 1 ~ 5 25fen <--> baoli
	{
		for(int i=0;i<n;i++)
		{
			vis[i]=1;
			dfs(vec[i], 1);
			vis[i]=0;
		}
		cout<<ans;
	}
	else if(n<= 2000)
	{
		ans=-1;
		if(m==1)
		{
			for(int i=0;i<n;i++)
			{
				ans=max(ans, vec[i]);
			}
			cout<<ans;
			return 0;
		}
		else if(m==n)
		{
			for(int i=0;i<n;i++)
			{
				ans=ans&vec[i];
			}
			cout<<ans;
			return 0;
		}
		else if(m==2)
		{
			for(int i=0;i<n;i++)
			{
				int maxn=-1;
				for(int j=0;j<n;j++)
				{
					if(i != j)
					{
						maxn=max(maxn, vec[i] & vec[j]);
					}
				}
				ans=max(ans, maxn);
			}
			cout<<ans;
			return 0;
		}
	}
	
}
