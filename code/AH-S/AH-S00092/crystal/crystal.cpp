#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
int n, m;
bool check(int x){
	int sum=0;
	for(int i=0; i<x; i++){
		int need=a[x-1]-a[i];
		sum+=need;
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	// freopen("err.log", "w", stderr);
	cin>>n>>m;
	a.resize(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	unordered_map<int, int> cnt;
	for(int i=0; i<n; i++){
		cnt[a[i]]++;
	}
	int maxx=-0x3f3f3f3f;
	for(int i=0; i<n; i++){
		maxx=max(maxx, cnt[a[i]]);
	}
	__int128 l=maxx, r=n-1;
	while(l<r){
		__int128 mid2=(l+r+1)>>1;
		int mid=mid2;
		if(check(mid2)){
			l=mid;
		}
		else r=mid-1;
	}
	int ret=l;
	cout<<ret;
	return 0;
}
