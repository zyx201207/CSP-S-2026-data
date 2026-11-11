#include<bits/stdc++.h>
using namespace std;
int n,m,TotalSum,ans;
int a[200005];
void dfs(int step,int idx = 1,int sum = 0){
	if(step == 0){
		ans = max(ans,sum);
		return ;
	}
	for(int i = idx;i <= n;i++){
		if(step == m) sum = a[i];
		dfs(step - 1,i+1,sum & a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1) TotalSum = a[i];
		TotalSum &= a[i];
	}
	sort(a+1,a+n+1);
	if(m == 1){
		cout << a[n];
		return 0;
	}
	if(m == n){
		cout << n;
		return 0;
	}
	dfs(m);
	cout << ans;
	return 0;
}
