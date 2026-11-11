/*
小R没长脑子吗，这都瞪不出来，活着干嘛 
*/
#include<bits/stdc++.h>
#define Hahaha using
#define I namespace
#define AK std
#define IOI ;
#define ll long long
#define N (int)(2e5 + 10)
Hahaha I AK IOI
ll a[N], aa[N], bb[N];
char c[N];

void work(){
	ll n;
	cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for(int i = n; i >= 1; i--){
		aa[i] = aa[i + 1] + a[i]; 
	} 
	for(int i = 1; i <= n; i++){
		bb[i] = bb[i - 1] + a[i];
	}
	ll ans = 0;
	for(int i = 1; bb[i - 1] + 1 <= sum / 2; i++){
		int l, r, L, R;
		l = 0, r = n + 1;
//		ll lst = ans;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if(aa[mid + 1] + 1 <= bb[i - 1] + 1){
				r = mid;
			}else{
				l = mid;
			}
		}
		R = r;
		l = 0, r = n + 1;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if(aa[mid + 1] + 1 <= bb[i]){
				r = mid;
			}else{
				l = mid;
			}
		}
		L = r;
		if(L < i){
			L = i;
		}
		if(R < i){
			R = i;
		}
//		cout << L << " " << R << " "; 
		if(L == R){
			if(c[L] != c[i]){
				ans += a[i];
			}
//			cout << ans - lst << "\n";
			continue;
		}
		for(int j = L; j <= R; j++){
			if(j == L){
				if(c[j] != c[i]){
					ans += bb[j] - (sum - bb[i]);
				}
				continue;
			}
			if(j == R){
				if(c[j] != c[i]){
					ans += (sum - bb[i - 1]) - bb[j - 1];
				}
				continue;
			}
			if(c[j] != c[i]){
				ans += a[j];
			}
		}
//		cout << ans - lst << "\n";
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int oT_To = 1;
//	cin >> oT_To;
	while(oT_To--){
		work();
	}
	return 0;
}
