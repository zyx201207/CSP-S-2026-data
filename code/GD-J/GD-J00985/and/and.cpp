#include<bits/stdc++.h>
using namespace std;
vector<int> a[200001];
map<int,vector<int>> map;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int idx=0;
		while(x)
		{
			a[i].push_back(x%2);
			map[++idx].push_back()									
			x/=2;
		}
	}
	return 0;
}

