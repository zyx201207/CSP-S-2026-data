#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll L=0;
deque<pair<int,char>> dq;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int a;char c;
		cin>>a>>c;
		L+=a;
		dq.push_back({a,c});
	}
	ll ans=0;
	while(!dq.empty()) {
		if(dq.front().second==dq.back().second) {
			if(dq.front().first>=dq.back().first) {
				dq.front().first-=dq.back().first;
				dq.pop_back();
			}
			else {
				dq.back().first-=dq.front().first;
				dq.pop_front();
			}
		}
		else {
			if(dq.front().first>=dq.back().first) {
				ans+=dq.back().first;
				dq.front().first-=dq.back().first;
				dq.pop_back();
			}
			else {
				ans+=dq.front().first;
				dq.back().first-=dq.front().first;
				dq.pop_front();
			}
		}
	}
	cout<<ans;
	return 0;
}
