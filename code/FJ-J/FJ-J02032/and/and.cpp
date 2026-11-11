#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n, m;
ll a[N];
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	ll ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
