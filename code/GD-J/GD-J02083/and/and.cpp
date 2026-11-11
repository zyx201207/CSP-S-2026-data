#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+8;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans=-1;
	for(int i=0;i<n-1;i++){
		ans=max(ans,a[i]&a[i+1]);
	}
	cout<<ans; 
	return 0;
}
