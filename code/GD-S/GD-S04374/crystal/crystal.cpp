#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
#define _for(i,a,b) for(int i=a,IM=b;i<=IM;i++)

const int N=5e5+9;
ll a[N];
/*
首先，操作后，答案的能量值肯定是原数组的一个元素 
那么我们考虑一个元素作为答案，其他元素想变为它，必须比它小  
*/
bool cmp (ll a,ll b) {
	return a>b;
}

void solve () {
	int n; ll m; cin>>n>>m;
	_for(i,1,n) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=0;
	queue<ll> qu;
	int now=1; ll sum=0;
	qu.push(a[1]);
	for(int r=2;r<=n;r++) {
		qu.push(a[r]); now++;
		sum+=qu.front()-a[r];
		while(sum>m) {
			ll x=qu.front(); qu.pop();
			sum-=(x-qu.front())*qu.size();
			now--;
		}
//		cout<<a[r]<<' '<<now<<' '<<sum<<endl;
		ans=max(ans,now);
	}
	cout<<ans;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
/*
大概花了1h 
5 5
1 2 4 8 9
*/
