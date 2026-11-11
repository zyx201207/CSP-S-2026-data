#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(n <= 500){
		int a_[200005];
		int b_[300005];
		int ans_[300005];
		int c_[200005];
		memset(a_, 0, sizeof a_);
		memset(b_, 0, sizeof b_);
		memset(c_, 0, sizeof c_);
		memset(ans_, 0, sizeof ans_);
		for(int i = 1;i <= n;i++)
			cin >> a_[i];
		for(int i = 1;i <= n;i++){
			int cnt = 0;
			memset(b_, 0, sizeof b_);
			for(int j = i;j <= n;j++){
				if(b_[a_[j]]){
					for(int k = b_[a_[j]] + 1;k <= cnt;k++){
						b_[c_[k]] = 0;
					}
					cnt = b_[a_[j]];
				}
				else{
					cnt++;
					c_[cnt] = a_[j];
					b_[a_[j]] = cnt;
				}
			}
			for(int j = 1;j <= cnt;j++){
				ans_[c_[j]]++;
			}
		}
		for(int i = 1;i <= m;i++){
			cout << ans_[i] << " ";
		}
		return 0;
	}
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i == 1) continue;
		if(flag && a[i] < a[i - 1]) flag = 0;
	}
	if(flag){
		for(int i = 1;i <= n;i++){
			if(a[i] != a[i + 1]){
				cout << i << " ";
			}
		}
		return 0;
	}
	
	return 0;
}
