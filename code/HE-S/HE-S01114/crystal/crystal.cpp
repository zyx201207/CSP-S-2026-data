#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lep(i,a,b) for(int i = a,ed##i = b;i <= ed##i; ++i)
#define rep(i,a,b) for(int i = a,ed##i = b;i >= ed##i; --i)
const int N = 5e5 + 7;
ll a[N],n,m,sum[N];
int find(int pos){
	int L = 1,R = pos,res = pos,cost;
	while(L <= R){
		int mid = (L + R) >> 1;
		cost = a[pos] * (pos - mid + 1) - (sum[pos] - sum[mid - 1]); 
		if(cost <= m) res = mid,R = mid - 1;
		else L = mid + 1; 
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	lep(i,1,n){cin >> a[i];}
	sort(a + 1,a + n + 1);
	lep(i,1,n) sum[i] = sum[i - 1] + a[i]; 
	int ans = 0;
	lep(i,1,n){
		ans = max(ans,i - find(i) + 1);
	}
	cout << ans << '\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8 
-3 -1 2 2 7
*/
