#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &v : a) cin >> v;
	
	vector<int> ans(m);
	for(int i = 0; i < n; i ++){
		
		vector<int> ap(m + 1, -1);
		vector<int> q(n, -1);
		int it = 0;
		for(int j = i; j < n; j ++){
			if(ap[a[j]] == -1){
				ap[a[j]] = it;
				q[it] = a[j];
				it ++;
			}
			else{
				while(it > ap[a[j]] + 1){
					it --;
					ap[q[it]] = -1;
				}
			}
		}
		for(int j = 0; j < it; j ++){
//			if(q[j] <= 0){
//				cout << i << ' ' << j << ' ' << it << endl;
//				cout << q[j] << endl;
//				cout << a.size() << endl;
//				for(int i = 0; i < it; i ++) cout << q[i] << ' ';
//			}
			ans[q[j] - 1] ++;
//			// debug
////			if(q[j] == 1) cout << i << ' ' << a[i] << ' ' << it << endl;
		}
	}
	for(auto &v : ans) cout << v << ' ';
	cout << endl;
}
