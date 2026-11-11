#include<bits/stdc++.h>
using namespace std;
const int N =5e5 + 5;
long long n,m;
long long  a[N],s[N];
bool check(int x){
	int ln = x - 1;
	for(int i = x;i <= n ;i++){ 
		if((long long)ln * a[i]-(s[i - 1] - s[i - 1 - ln + 1 - 1]) <= m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n;i++){
		s[i] += s[i - 1] + a[i];
		
	}
	int l = 1,r = n,res,mid;
	while(l <= r){
		mid = (r + l) >> 1;
		if(check(mid)){
			l = mid + 1;
			res = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << res;
	return 0;
}
