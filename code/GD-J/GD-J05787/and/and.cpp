#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,ans=0;
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=m;i++){
		for(int i=2;i<=n-i;i++){
			ans=max(ans,a[i]&a[i-1]);
		}
	}
	cout<<ans;
	
	return 0;
}
