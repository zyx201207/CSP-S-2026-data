#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N,M;
vector<ll> a;

bool check(ll x){
	ll mined=1e18;
	ll ned=0;
	for(int i=1;i<x;i++){
		ned+=a[x]-a[i];
	}
	mined=min(mined,ned);
	for(int i=1;i<=N-x+1;i++){
		ned-=a[i+x-2]-a[i-1];
		ned+=(a[i+x-1]-a[i+x-2])*x;
		mined=min(mined,ned);
	}
	return mined<=M;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>N>>M;
	a.resize(N+1,0);
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	
	int l=1,r=N;
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	
	cout<<l;
	
	return 0;
}
