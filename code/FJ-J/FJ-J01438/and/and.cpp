#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int last=30;
	map<int,vector<int> > mp;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ans=0;
	while(a.size()>m) {
		mp.clear();
		for(int i=1; i<a.size(); i++) {
			for(int j=0; j<=last; j++) {
				if(a[i]&(1<<j))mp[j].emplace_back(a[i]);
			}
		}
		int idx=-1;
		for(int i=last; i>=0; i--) {
			if(mp[i].size()>=m) {
				idx=i;
				ans+=(1<<i);
				break;
			}
		}
		if(idx==-1) {
			break;
		}
//		cout<<idx<<"\n"; 
		a=mp[idx];
//		for(auto x:a)cout<<x<<" ";
//		cout<<"\n";
		last=idx-1;
	}
	cout<<ans<<"\n";
	return 0;
}

