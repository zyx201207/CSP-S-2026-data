#include<iostream>
using namespace std;
int n,m;
int mmax=-1;
int a[200005];
int an[200005];
void dfs(int num, int now, int cnt)
{
	if(cnt==0){
		mmax = max(mmax, num);
		return;
	}
	if(now==n){
		return;
	}
	dfs(num, now + 1, cnt);
	num &= a[now];
	dfs(num, now + 1, cnt - 1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// freopen("and.in", "r", stdin);
	// freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n-m+1;i++){
		dfs(a[i], i, m-1);
	}
	cout << mmax;
	return 0;
}
