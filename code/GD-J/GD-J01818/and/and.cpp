#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <int> st;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		int a;
		cin>>a;
		st.push_back(a);
		if((a>>30)&1) {
			cnt++;
		}
	}
	sort(st.begin(),st.end(),greater <int>());
	int ans=0;
	for(int i=30; i>=0; i--) {
		int l=0,r=st.size()-1,cnt=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if((st[mid]>>i)&1) {
				l=mid+1;
				cnt=mid+1;
			} else {
				r=mid-1;
			}
		}
		if(cnt>=m) {
			ans=ans+(1ll<<i);
			while(!st.empty()&&(((st.back()>>i)&1)==0)) {
				st.pop_back();
			}
		}
		for(auto &j:st) {
			if((j>>i)&1) {
				j=j-(1ll<<i);
			}
		}
		sort(st.begin(),st.end(),greater <int>());
	}
	cout<<ans;
	return 0;
}
