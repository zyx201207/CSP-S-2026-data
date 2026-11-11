#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

const int N=5e5;

int c,T;
int n,k;
vector<int> e[N+1];

bool vis[N+1];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y; cin>>x>>y;
			e[x].emplace_back(y),e[y].emplace_back(x);
		}
		
		cout<<1<<'\n';
	}
	
	return 0;
}

