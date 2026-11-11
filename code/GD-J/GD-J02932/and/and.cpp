#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > q;
int an(int x) {
	int cnt=0;
	while(x) {
		if(x%2==1) cnt++;
		x/=2;
	}
	return cnt;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1,x;i<=n;i++) {
		cin>>x;
		q.push({an(x),x});
	}
	auto f=q.top();q.pop();
	int ans=f.second;
	while(--m) {
		f=q.top();q.pop();
		if(ans>=f.second && f.first==an(ans&f.second)) ans&=f.second;
		else {
			if(an(ans&f.second)==an(ans)-1) ans&=f.second;
			else m++;
		}
	}
	cout<<ans;
	return 0;
} 
