#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200050];
long long da = -1;
void dfs(long long num, long long i, long long sum){
	if(num == m){
		da = max(da, sum);
		return;
	}
	if(i > n){
		return;
	}
	//Òª 
	dfs(num + 1, i + 1, sum & a[i]);
	//²»Òª
	dfs(num, i + 1, sum); 
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	long long maxn = -1;
	bool b = true,c = true;
	long long qr = 0;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		maxn = max(maxn, 1LL * a[i]);
		if(a[i] >= 4){
			b = false;
		}
		if(a[1] == 0 and a[i] == qr){
			qr++;
		}
		else{
			c = false;
		}
	}
	if(m == 1){
		cout<<maxn;
		return 0;
	}
	else if(m == 2){
		long long num = -1;
		for(long long i = 1;i <= n;i++){
			for(long long j = i + 1;j <= n;j++){
				num = max(num, 1LL * a[i] & a[j]);
			}
		}
		cout<<num;
	}
	else if(m == n){
		long long num = a[1] & a[2];
		for(long long i = 3;i <= n;i++){
			num = num & a[i];
		}
		cout<<num;
	}
	else if(b == true){
		long long num = 1e9, sum = 0;
		for(int qw = 3;qw >= 1;qw--){
			for(long long i = 1;i <= n;i++){
				if(sum == m){
					break;
				}
				if(a[i] == qw){
					num = num & a[i];
					sum++;
				}
			}
		}
		if(sum != m){
			cout<<0;
		}
		else{
			cout<<sum;
		}
	}
	else if(c == true){
		cout<<m * 3;
	}
	else{
		dfs(0, 1, 2e30);
		cout<<da;
	}
	return 0;
}
