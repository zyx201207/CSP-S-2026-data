#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),cnt(m,0);
	for(int i = 0;i < n;i++) cin>>a[i];
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++) cnt[a[j] - 1]++;
	}
	for(int i = 0;i < m;i++) cout<<cnt[i]<<" ";
	return 0;
}
