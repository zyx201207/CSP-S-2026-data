#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll, char>
#define fi first
#define se second
using namespace std;
ll n, m, a[500005], b[500005], cnt[300005], pre[300005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 500){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			b[j] = a[j];
		}
		for(int j = 1;j <= m;j++){
			pre[j] = 0;
		}
		for(int j = i;j <= n;j++){
			if(pre[b[j]] == 0){
				pre[b[j]] = j;
			}
			else{
				for(int k = pre[b[j]];k < j;k++){
					if(pre[b[k]] == k){
						pre[b[k]] = 0;
					}
					b[k] = 0;
				}
				pre[b[j]] = j;
			}
		}
		for(int j = i;j <= n;j++){
			cnt[b[j]]++;
		}
	}
	}
	else{
		for(int i = n;i >= 1;i--){
			if(cnt[a[i]] == 0){
				cnt[a[i]] = i;
			}
		}
	}
	cout << cnt[1];
	for(int i = 2;i <= m;i++){
		cout << " " << cnt[i];
	}
	return 0;
}
