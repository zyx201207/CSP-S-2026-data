#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[500005], ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int T=1; T<=n; T++)
	{
		vector<int> desk;
		desk.reserve(n);
		map<int, int> st;
		for(int i=T; i<=n; i++)
		{
			if(st[a[i]]==0)
			{
				desk.push_back(a[i]);
				st[a[i]]++;
//				cout<<T<<") add: " << a[i]<<"\n";
//				for(int i=0; i<desk.size(); i++)cout<<desk[i]<<' ';
//				cout<<'\n';
//				for(auto d:st) if(d.second) cout<<d.first<<' ';
//				cout<<'\n';
			}
			else
			{
				while(desk.back()!=a[i]) st[desk.back()]--, desk.pop_back();
//				cout<<"pop!\n";
//				for(int i=0; i<desk.size(); i++)cout<<desk[i]<<' ';
//				cout<<'\n';
//				for(auto d:st) if(d.second) cout<<d.first<<' ';
//				cout<<'\n';
			}
		}
		for(auto d:st) if(d.second) ans[d.first]++;
	}
	for(int i=1; i<=m; i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

