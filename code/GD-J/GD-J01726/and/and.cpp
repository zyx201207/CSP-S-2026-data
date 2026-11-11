#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans;
long long dfs(long long sum,long long v,long long x){
    long long mx=0;
    if (v==m) return sum;
	for (long long i=x+1; i<=n; i++){
		mx=max(mx,dfs(sum&a[i],v+1,i));
	}
	return mx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (long long i=1; i<=n; i++) cin >> a[i];
	for (long long i=1; i<=n; i++){
		ans=max(ans,dfs(a[i],1,i));
	}
	cout << ans;
}
