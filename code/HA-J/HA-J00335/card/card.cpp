#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 1e5 + 5;
int n, m;
int a[N];
int ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		vector<int> s;
		s.push_back(a[i]);
		for (int j = i + 1; j <= n; j++){
			if (s[j - 2] == a[j]){
				s.pop_back();
			}
			s.push_back(a[j]);
		}
		for (auto x : s){
			ans[x]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
} 