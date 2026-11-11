#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n ,m;
	cin >> n >> m;
	vector<long long> a(n),sum(n),count(n),ccfs(n);
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	int k,b;
	for(int i = 0;i < n;i ++){
		int r = a[n];
		for(int i = 0;i < n;i++){
			k += r - a[i];
			b += k;
			k = 0;
		}
		sum[i] += b;
		cout << b << " ";
		b = 0;
		r --;
	}
	int z;
	for(int i = 0;i < n;i ++){
		if(a[i] <= a[i - 1]){
			z = i;
		}
	}
	int c,f;
	for(int i = 0;i < n;i ++){
		int m = a[z];
		for(int i = 0;i < n;i ++){
			c += m - a[i];
			f += c;
			c = 0;
		}
		count[i] += f;
		c = 0;
	}
	sort(count.begin(),count.end());
	int ans;
	for(int i = 0;i < n;i ++){
		ccfs[i] += a[z] - count[i];
	}
	int s;
	for(int b = 0;b < n;b ++){
		
		s += ccfs[b];
		if(s > m){
			ans --;
			cout << ans << endl;
			return;
		}else if(s == m){
			ans ++;
			cout << ans << endl;
			return; 
		}
		ans ++;
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
} 
