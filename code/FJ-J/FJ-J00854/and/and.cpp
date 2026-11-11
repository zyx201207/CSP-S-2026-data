#include <bits/stdc++.h>
using namespace std;

int a[200010];
int n,m;
int ans;
void dfs(int i,int k,int sum){
	if (k==0){
		ans=max(ans,sum);
		return;
	}
	for (int j=i+1;j<=n;j++){
		dfs(j+1,k-1,sum&=a[j]);
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++){
		dfs(i+1,m-1,a[i]);
	}
	cout << ans;
	return 0;
}
