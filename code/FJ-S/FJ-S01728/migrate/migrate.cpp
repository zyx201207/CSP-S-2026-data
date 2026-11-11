#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005];
int next_add(int q){
	long long cnt = 0,can = q,cannot = q-1;
	for (int i = 1;i + q - 1 <= n;i++){
		if (a[q-1+i] - a[q-1] > d) break;
		cannot++;
	}
	for (int i = 1;i + q <= n;i++){
		if (a[q+i] - a[q] > d) break;
		can++;
	}
	cnt += can-cannot;
	if (a[can+1]-a[can] < d && can > cannot && can != n) cnt += next_add(can);
	return cnt;
}
int left_add(int q){
	long long cnt = 0,can = q,cannot = q+1;
	for (int i = 1;q + 1 - i >= 1;i++){
		if (a[q+1] - a[q+1-i] > d) break;
		cannot--;
	}
	for (int i = 1;q - i <= n;i++){
		if (a[q] - a[q-i] > d) break;
		can--;
	}
	cnt += max(cannot-can,0ll);
	if (a[can]-a[can-1] < d && can < cannot && can != 1) cnt += left_add(can);
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans = 0;
		for (long long i = 1;i <= n;i++) cin>>a[i];
		for (long long i = 1;i <= n-3;i++){
			long long can_fly = 0,two_fly = 0;
			for (long long j = 1;i + j<= n;j++){
				if (a[i+j]-a[i] > d) break;
				can_fly++;
			}
			if (can_fly < 2) continue;
			long long q = i + can_fly -1;
			for (long long j = 1;q + j <= n;j++){
				if (a[q+j]-a[q] > d) break;
				if (a[q+j]-a[q-1] > d) ans++;
				two_fly++;
			}
			long long p = q + two_fly;
			if (a[p]-d <= a[q-1]) continue;
			//cout<<ans<<" ";
			ans += next_add(p);
			ans += left_add(p);
			//cout<<ans<<" ";
		}
		cout<<ans<<"\n";
	}
}
