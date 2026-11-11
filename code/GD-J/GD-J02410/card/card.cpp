#include <bits/stdc++.h>
using namespace std;
#define int long long
#define OI ios::sync_with_stdio(0);cin.tie(0)
#define end '\n'
#define pii pair<int,int>

const int N=5e5+5;
int n,m,a[N];
bool isa;

inline void solve1()
{
	vector<int> ans(m+5,0);
	for (int i=1;i<=n;i++)
	{
		vector<int> card;
		card.reserve(n+5);
		bitset<205> vis;
		vis.reset();
		
		for (int j=i;j<=n;j++)
		{
			int k=a[j];
			if (vis[k]==0) 
			{
				card.emplace_back(k);
				vis[k]=1;
			}
			else
			{
				while (card.back()!=k) 
				{
					vis[card.back()]=0;
					card.pop_back();
				}
			}
		}
		
		for (int j:card) ans[j]++;
	}
	
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<endl;
	
	return ;
}

inline void solve2()
{
	vector<int> ans(m+5,0);
	for (int i=1;i<=n;i++)
	{
		vector<int> card;
		card.reserve(n+5);
		
		for (int j=i;j<=n;j++)
		{
			int k=a[j];
			if (!card.empty()&&card.back()==k) {;}
			else card.emplace_back(k);
		}
		
		for (int j:card) ans[j]++;
	}
	
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<endl;
	
	return ;
}

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

//	freopen("test4.in","r",stdin);
	
	OI;
	
	cin>>n>>m;
	isa=1;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (i>1&&a[i-1]>a[i]) isa=0;
	}
	
	if (n<=500) 
	{
		solve1();
		return 0;
	}
	else if (isa) 
	{
		solve2();
		return 0;
	}
	else solve1();
	return 0;
}
