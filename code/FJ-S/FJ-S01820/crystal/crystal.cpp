#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(long long i=1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=1;
	
	for(long long i=1; i < n; i++){
		if(m <= 0) break;
		long long x = (a[i+1]-a[i])*i;
		if(x <= m){
			a[i] = a[i+1];
			ans++;
			m -= x;
		}
	}
	cout<<ans;
	return 0;
}
