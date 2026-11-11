#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000010;
namespace cza{
	int Cid, T;
	int n, d;
	int x[N];
	int pre[N], suf[N];
	int pre1[N], suf1[N];
	int main(){
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> Cid >> T;
		while(T--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				cin >> x[i];
			}
			
			pre[0] = 1;
			for(int i = 1; i <= n; i++){
				pre[i] = pre[i - 1];
				while(x[i] - x[pre[i]] > d) pre[i]++;
			}
			pre[n + 1] = n + 1;
			suf[n + 1] = n;
			for(int i = n; i >= 1; i--){
				suf[i] = suf[i + 1];
				while(x[suf[i]] - x[i] > d) suf[i]--;
			}
			suf[0] = 0;
			
			pre1[1] = 0;
			for(int i = 2; i <= n; i++){
				if(pre[i] == i){
					pre1[i] = 0;
				}else{
					if(suf[pre[i]] != i){
						pre1[i] = 0;
					}else{
						pre1[i] = pre1[pre[i]] + min(i, pre[i + 1]) - pre[i];
					}
				}
			}
			
			suf1[n] = 0;
			for(int i = n - 1; i >= 1; i--){
				if(suf[i] == i){
					suf1[i] = 0;
				}else{
					if(pre[suf[i]] != i){
						suf1[i] = 0;
					}else{
						suf1[i] = suf1[suf[i]] + suf[i] - max(suf[i - 1], i);
					}
				}
			}
			
			int ans = 0;
			for(int i = 2; i < n - 1; i++){
				int pre2 = 0, suf2 = 0;
				if(pre[i] == i) pre2 = 0;
				else{
					if(suf[pre[i]] != i + 1){
						if(suf[pre[i]] == i){
							pre2 = min(i, pre[i + 2]) - min(i, pre[i + 1]);
						}else{
							pre2 = 0;
						}
					}else{
						pre2 = pre1[pre[i]] + min(i, pre[i + 2]) - pre[i];
					}
				}
				
				if(suf[i + 1] == i + 1) suf2 = 0;
				else{
					if(pre[suf[i + 1]] != i){
						if(pre[suf[i + 1]] == i + 1){
							suf2 = max(i, suf[i]) - max(i, suf[i - 1]);
						}else{
							suf2 = 0;
						}
					}else{
						suf2 = suf1[suf[i + 1]] + suf[i + 1] - max(suf[i - 1], i + 1);
					}
				}
				
				ans += pre2 * suf2;
			}
			cout << ans << '\n';
		}
		return 0;
	}
}
signed main(){
	return cza::main();
}
