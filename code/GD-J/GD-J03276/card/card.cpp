#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool fa = 1;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if((i != 1) && (a[i] < a[i - 1])) fa = 0;
	}
	if(fa){
		int now = 1;
		for (int i = 1; i < n && now < m; i++){
			if(a[i] == now && a[i + 1] != a[i]){
				cout << i << ' ';
				now++;
			}
		}
		cout << n;
	}else{
		stack<int> st;
		vector<bool> has(m + 1, 0);
		vector<int> cnt(m + 1, 0); 
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				if(has[a[j]]){
					while(st.top() != a[j]) st.pop();
				}else st.push(a[j]);
			}
			while(!st.empty()){
				int t = st.top();
				st.pop();
				cnt[t]++;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << cnt[i] << " ";
		}
	}
	cout << '\n';
	return 0;
}
