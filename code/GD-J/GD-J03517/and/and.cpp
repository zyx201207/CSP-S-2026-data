#include<bits/stdc++.h>
using namespace std;
long long f(long long x){
	long long t = 0;
	while(x){
		x >>= 1;
		t++;
	}
	return t;
}
bool t(long long x,long long num){return x & (1 << num);}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mx = 0;
	cin >> n >> m;
	vector<long long> a(n); 
	for(int i = 0;i < n;i++){
		long long k;
		cin >> k;
		a[i] = k;
		mx = max(mx,f(k));
	}
	mx--;
	int ans = 0;
	for(int i = mx;i >= 0;i--){
		int cnt = 0;
		for(int j = 0;j < n;j++) if(t(a[j],i)) cnt++;
		if(cnt >= m){
			ans |= 1 << i;
			for(int j = 0;j < n;j++) if(!t(a[j],i)) a[j] = 0;
		}
	}
	cout << ans;
	return 0;
}
