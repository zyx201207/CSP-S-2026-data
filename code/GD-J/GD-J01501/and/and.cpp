#include <bits/stdc++.h>
using namespace std;
long long n,m;
bool issame = true;
long long a[200005];
long long ans = 0;
void dfs(long long lt,long long dt,long long sum){
	if(dt > m){
		ans = max(ans,sum);
		return;
	}
	for(long long i = lt + 1;i<= n - m + dt;i++){
		if(sum == -11){
			dfs(i,dt+1,a[i]);
		}
		dfs(i,dt+1,sum&a[i]);
	}
	return;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(i > 1){
			if(a[i] != a[i-1]){
				issame = false;
			}
		}
	}
	if(issame){
		cout<<a[1];
		return 0;
	}
	
	dfs(0,1,-11);
	cout<<ans;
	return 0;
}
