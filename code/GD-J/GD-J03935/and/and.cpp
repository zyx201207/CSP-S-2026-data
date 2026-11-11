#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;

int n, m;
int a[MAXN];

vector<int> v[32];
vector<int> cur;

int ans;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int w=1;w<=30;w++){
			if(a[i] & (1 << (w-1))){
				v[w].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++) cur.push_back(i);
	for(int w=30;w>=1;w--)
	{
		vector<int> ad;
		int cn = 0, wn = 0;
		while(cn < cur.size() && wn < v[w].size())
		{
			if(cur[cn] == v[w][wn])
			{
				ad.push_back(cur[cn]);
				cn++, wn++;
			}
			else if(cur[cn] < v[w][wn]) cn++;
			else wn++;
		}
		if(ad.size() >= m)
		{
			ans += (1 << (w-1));
			cur = ad;
		}
	}
	cout<<ans;
	return 0;
}
