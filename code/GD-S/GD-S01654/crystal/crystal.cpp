#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,t,l=2,a[500001],clc=1;
deque<ll>q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	q.push_back(a[1]);
	while(l<=n){
		while(t+(ll)q.size()*(a[l]-q.back())<=m and l<=n){
			t+=((ll)q.size()*(a[l]-q.back()));
			q.push_back(a[l]);
			l++;
		}
		clc=max(clc,(ll)q.size());
		t-=(q.back()-q.front());
		q.pop_front();
	}
	cout<<clc;
	return 0;
}
