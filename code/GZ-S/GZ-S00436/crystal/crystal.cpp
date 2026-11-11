//GZ-S00436 都匀市第一中学 林孝煊 
#include <bits/stdc++.h>
#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long

using namespace std;
int n; LL m; LL a[500007], sum[500007];

bool check(int X){
	//printf("check starts\n");
	for (int i = 1; i <= n - X + 1; i++){
		LL total = 0;
		LL lost_one = a[i + X - 1];
		LL m_sum = sum[i + X - 2] - sum[i - 1];
		/*for (int j = i; j <= i + X - 2; j++){
			total += lost_one - a[j];
		}*/
		total = (X - 1) * lost_one - m_sum;
		if (total <= m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	//for (int i = 1; i <= n; i++) printf("%lld", sum[i]);
	
	int l = 0, r = n, ans;
	while (l <= r){
		int mid = (l + r) / 2;
		//printf("%d\n", mid);
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
		//printf("l=%d, r=%d\n", l, r);
	}
	
	printf("%d", ans);
	
	return 0;
}
