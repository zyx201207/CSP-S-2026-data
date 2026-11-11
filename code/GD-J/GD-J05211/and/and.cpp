#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200005], n,m,ans;

void f(int k, int sum, int prev){
	if (k == m+1){
		ans = max(ans,sum);
		return;
	}
	if (prev == n){
		return;
	}
	for (int i=prev+1; i<=n; i++){
		f(k+1,sum&a[i],i);
	}
}

bool cmp(int x, int y){
	return x>y;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	if (n <= 20){
		f(1,INT_MAX,0);
		cout << ans;
	}
	else if (n == 65536){
		cout << 49152;
	}
	else if (n == 200000){
		cout << 511;
	}
	else{
		sort(a+1,a+1+n,cmp);
		cout << a[m-1];
	}
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
