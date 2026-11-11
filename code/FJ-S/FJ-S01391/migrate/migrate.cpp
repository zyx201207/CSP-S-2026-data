#include<bits/stdc++.h>
using namespace std;
long long n, d, zb[2000005], head, tail, cnt;
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> zb[i];
	}
	int h = d / (zb[2]-zb[1]);
	h = h * (zb[2]-zb[1]);
	head = tail = 1;
	for(int i = 2; i <= n; i++){
		tail = i;
		int dis = zb[tail] - zb[head];
		if((zb[tail] - zb[tail-1]) > d){
			break;
		}
		while(dis >= 2 * h){
			head++;
			dis = zb[tail] - zb[head];
		}
		if(head > tail)break;
		if(dis > h){
			cnt++;
		}
	}
	cout << cnt << "\n";
	cnt = 0;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}