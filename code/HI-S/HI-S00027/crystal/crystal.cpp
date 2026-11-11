#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+5;

int n, m, ans;
int a[N], s[N];

bool check(int mid){ 	//看为mid时是否符合 
	for(int r = mid;r<=n;r++){
		int l = r - mid + 1;
		int cost = a[r]*mid-(s[r]-s[l-1]);
		if(cost<=m){
			return true;
		}
		else{
			return false;
		}
	}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	
	int l = 1, r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			l++;
		}
		else r--;
	} 
	cout << ans;
	return 0;
} 
