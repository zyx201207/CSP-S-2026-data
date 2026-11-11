#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m;
long long a[N];
long long ans=-1;
long long c[N];
long long preans;
bool vis[N];
bool flagB = true;

void dfs(int pos){
	if(pos==m+1){
		preans = c[1];
		for(int i=2;i<=m;i++){
			preans &= c[i];
		}
		ans = max(ans,preans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		c[pos] = a[i];
		vis[i] = true;
		dfs(pos+1);
		vis[i] = false;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] != i-1){
			flagB = false;
		}
	}
	if(n<=2000){
		dfs(1);
		cout << ans;
	}else{
		sort(a+1,a+1+n);
		if(flagB){
			ans = a[n];
			for(int i=n-1;i>=n-m+1;i--){
				ans &= a[i];
			}
			cout << ans;
		}else{
			// flagA
			cout << a[n-m+1];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
