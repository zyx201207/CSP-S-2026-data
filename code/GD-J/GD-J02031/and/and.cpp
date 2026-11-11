#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
priority_queue<pair<ll,int>,vector<pair<ll,int>>> pq;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		ll pp,bi;
		cin>>pp;
		bi=__builtin_popcountll(pp);
		pq.push({bi,pp});
	}
	int cur=pq.top().second;
	pq.pop();
	for(ll i=1;i<m;i++){
		ll u=pq.top().second;
		pq.pop();
		cur=cur&u;
	}
	cout<<cur;
	return 0;
}
