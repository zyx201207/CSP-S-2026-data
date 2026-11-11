#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum = 0;
vector<pair<int,char>>a;

void dfs(int l,int r) {
	if(l==r)return;
	if(l>r)return;
	if(l>n||r<1)return;
	int minn = min(a[l].first,a[r].first);
	a[l].first-=minn,a[r].first-=minn;
	if(a[l].second!=a[r].second)sum+=minn;
	if(!a[l].first)l++;
	if(!a[r].first)r--;
	dfs(l,r);
}

signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	dfs(1,n);
	cout<<sum<<endl;
	return 0;
}
