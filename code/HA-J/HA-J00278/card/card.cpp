#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
typedef vector<int> V;
map<int,V> mp;
int a[N];
int lst[N];
int cnt[N];
int ans[N];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	V p;
	p.push_back(a[n]);
	mp[n]=p;
	lst[a[n]]=n;
	cnt[n]++;
	for(int i=n-1; i>=1; i--) {
		if(lst[a[i]]==0) {
			lst[a[i]]=i;
			V tmp=mp[lst[a[i+1]]];
			tmp.push_back(a[i]);
			mp[i]=tmp;
			cnt[i]++;
		} else {
			cnt[lst[a[i]]]++;
		}
	}
	for(auto i:mp) {
		V k=i.second;
		for(int j:k) {
			ans[j]+=cnt[i.first];
		}
	}
//	ans[a[n]]=n;
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
