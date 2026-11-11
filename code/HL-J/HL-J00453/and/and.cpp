#include <bits/stdc++.h>
using namespace std;
int n,m,a[200002],maxx;
long long ans;
void solve(long long sum,int x,int l){
	if(l == m){
		ans = max(ans,sum);
		return;
	}
	for(int i = x + 1;i <= n;i++)
		solve(sum & a[i],i,l + 1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if(m == 1){
		cout << maxx << endl;
		return 0;
	}
	for(int i = 1;i <= n;i++)
		solve(a[i],i,1);
	cout << ans << endl;
	return 0;

}
