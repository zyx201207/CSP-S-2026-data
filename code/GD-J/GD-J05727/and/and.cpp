#include<bits/stdc++.h>
using namespace std;

long long a[200005], ans, n, m;
bool used[200005];

void dfs(long long t, long long sum, long long num){
	if(num > m){
		ans = max(ans, sum);
		return;
	}
	for(long long i = 1; i <= n; i++){
		if(!used[i]){
			used[i] = 1;
			dfs(i, sum&a[i], num+1);
			used[i] = 0; 
		}
	} 
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(long long i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(long long i = 1; i <= n; i++){
		dfs(i, a[i], 1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
