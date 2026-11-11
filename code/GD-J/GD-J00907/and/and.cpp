#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[200010];
bool cmp(long long x, long long y){
	return x > y;
}
void find1(){
	long long ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
			ans = max(ans, a[i] & a[j]);
		}
	}
	cout << ans << endl;
}
long long find2(){
	sort(a + 1, a + n + 1, cmp);
	long long h = a[1];
	a[1] = 0;
	return h;
} 

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	if(m == 1) cout << a[1] << endl;
	else if(m == n){
		long long cnt = 0;
		cnt = a[1];
		for(int i = 2; i <= m; i ++){
			cnt = cnt & a[i];
		}
		cout << cnt << endl;
	}
	else if(m == 2){
		find1();
	}
	else{
		long long sum = 0;
		sum = find2();
		for(int i = 1; i < m; i ++){
			sum = sum & find2();
		}
		cout << sum;
	}
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
