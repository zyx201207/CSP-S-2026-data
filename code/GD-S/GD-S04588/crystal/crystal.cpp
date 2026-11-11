#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N],p[N];
int n,m;

bool check(int mid,int r){
	if(a[r] * (r - mid + 1) - (p[mid] - p[r + 1]) > m) return 0;
	else return 1;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	for(int i = n;i >= 1;i --){
		p[i] = p[i + 1] + a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		int l = 1,r = i,mid;
		while(l <= r){
			mid = ((l + r) >> 1);
			if(check(mid,i)){
				ans = max(ans,i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} 
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/

