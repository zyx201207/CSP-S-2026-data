#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1005];
ll ans = 0;
void dfs(int step,ll sum){
	if(step > n){
		if(sum <= 100){
			ans++;
		}
		return;
	}
	dfs(step + 1,sum);
	dfs(step + 1,sum + a[step]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dfs(1,0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
