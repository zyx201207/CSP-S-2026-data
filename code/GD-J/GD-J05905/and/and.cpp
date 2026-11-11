#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,m;
int a[N];
int ans;
void dfs(int l,int r,int cnt){
	if (r>=n) return;
	ans = max(ans,cnt);
	cnt = a[l];
	for (int i=l+1;i<=r;i++){
		cnt = (cnt and a[i]);
	}
	dfs(l+1,r+1,cnt);
}
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool bo = 1;
	bool bo1=0,bo2=0,bo3=0;
	for (int i=0;i<n;i++) {
		cin >> a[i];
		if (a[i] > 3) bo = 0;
		if (a[i]==1)bo1 = 1;
		if (a[i]==2)bo2 = 1;
		if (a[i]==3)bo3 = 1;
	}
	int sum = a[0];
	if (n==m){
		for (int i=1;i<n;i++) sum = (sum and a[i]);
		cout << sum;
		return 0;
	}
	if (m==n-1){
		int inpet = 0;
		for (int i=0;i<n;i++){
			if (a[i] == 0) {
				inpet = i;
				break;
			}
		}
		for (int i=1;i<n;i++){
			if (i!=inpet) sum = (sum and a[i]);
		}
		cout << sum;
		return 0;
	}
	if (m==1||m==2){
		sum = 0;
		int xia = 0;
		for (int i=0;i<n;i++){
			if (sum < a[i]) xia = i;
			sum = max(sum,a[i]);
		}
		if(m==1){
			cout << sum;
			return 0;
		}
		int mx = 0;
		for (int i=0;i<n;i++){
			if (i == xia) continue;
			int ans1 = sum and a[i];
			mx=max(mx,ans1);
		} 
		cout << mx;
		return 0;
	}
	if (bo){
		if (bo3&&bo2) {
			cout << 2;
			return 0;
		}
		if (bo3&&bo1&&!bo2){
			cout << 1;
			return 0;
		}
	}
	dfs(0,m,0);
	cout << ans;
	return 0;
}
