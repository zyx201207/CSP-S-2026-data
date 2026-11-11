#include<bits/stdc++.h>
using namespace std;

long long n , m;
long long a[200010];
bool cmp(long long x, long long y) {
	return x > y;
}
long long ans = 0;
void dfs (long long dep , long long chos, long long now){
	if(dep == n || chos == m){
		if(chos == m) {
			ans = max (ans , now);
		}	
		return;
	}
	//cout << now << endl;
	if(chos == 0) {
		dfs(dep+1,0,0);
		dfs(dep+1,1,a[dep]);
	}else {
		dfs(dep+1,chos + 1,now & a[dep]);
		dfs(dep+1,chos,now);
	}
}

void solve()
{
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}sort(a,a+n,cmp);
	if(0 && n <= 2000) {
		dfs(0,0,0);
	}
	else {
		long long sum = 0;
		for(int k = 0;k<n-m;k++){
			sum = a[k];
			for(int i = k+1;i<k+m;i++){
				//cout << a[i] << " " << ans << endl;
				sum &= a[i];
			}
			ans = max (ans , sum);
		}
	}
	cout << ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

