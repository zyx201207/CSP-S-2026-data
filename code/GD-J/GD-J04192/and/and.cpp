#include <bits/stdc++.h> 
using namespace std;
#define ll long long

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	vector<ll> a(N+1,0);
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			ans=max(ans,a[i] & a[j]);
		}
	}
	
	cout<<ans;
	
	return 0;
}
