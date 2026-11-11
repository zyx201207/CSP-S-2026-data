#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1);
	vector<long long> ans(m+1);
	for(long long i=1; i<=n; i++) cin>>a[i];
	for(long long i=1; i<=n; i++) {
		vector<bool> cnt(m+1);
		stack<long long> st;
		for(long long j=i; j<=n; j++) {
			if(cnt[a[j]]==0) cnt[a[j]]=1,st.push(a[j]);
			else {
				while(!st.empty()&&st.top()!=a[j]) {
					cnt[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for(long long i=1; i<=m; i++) {
		cout<<ans[i];
		if(i!=m) cout<<" ";
		else cout<<"\n";
	}
	return 0;
}
// 13s on card/card5.in, TLE!!!!

