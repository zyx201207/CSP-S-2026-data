#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;

int n,m;
int a[N],sum[N];

int func(int l,int r){
	return (r-l+1)*a[r] - (sum[r]-sum[l-1]);
}

bool check(int len){
	int minn=LONG_LONG_MAX;
	for(int l=1;l<=(n-len+1);l++){
		int r=l+len-1;
		minn = min(minn, func(l,r));
	}
	if(minn <= m) return 1;
	else return 0;
}

void Input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
}

void Solve(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	int L = 0, R = n, ans=0;
	while(L <= R){
		int mid = (L+R)>>1;
		if(check(mid)){
			ans = max(ans, mid);
			L = mid+1;
		}else{
			R = mid-1;
		}
	}
	cout << ans;
}

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	//cin >> T;
	while(T--){
		Input();
		Solve();
	}
	
	return 0;
}
