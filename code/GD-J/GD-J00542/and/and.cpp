#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
long long p[N][33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int k = 0;k < 30;k++){
			if((1 << k) & a[i]){
				p[i][k] = 1;
			}
			else{
				p[i][k] = 0;
			}
		}
	}
	long long ans = 0;
	vector<int> old_id;
	vector<int> new_id;
	for(int i = 1;i <= n;i++){
		old_id.push_back(i);
	}
	for(int k = 30;k >= 0;k--){
		long long sum = 0;
		for(auto i : old_id){
			if(p[i][k] == 1){
				new_id.push_back(i);
				sum++;
			} 
		}
		if(sum >= m){
			ans += (1 << k);
			old_id.clear();
			for(auto i : new_id){
				old_id.push_back(i);
			}
			new_id.clear();
		}
		else{
			new_id.clear();
		}
	}
	cout << ans;
	return 0;
}
