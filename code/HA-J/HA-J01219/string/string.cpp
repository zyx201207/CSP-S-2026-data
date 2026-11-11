#include <bits/stdc++.h>
using namespace std;

struct li{
	int num;
	char c;
};

vector<li> a;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++){
		li x;
		cin >> x.num >> x.c;
		a.push_back(x);
	}
	
	long long ans = 0;
	int temp = 0;
	int l_=0, r_=n-1;
	bool flag = 0;
	bool first = 1;
	while(l_ < r_){
		int n_l = a[l_].num, n_r = a[r_].num;
		if (!first){
			if (flag) n_l = temp;
			else n_r = temp;
		}
		first = 0;
		if (n_l > n_r){
			temp = n_l-n_r;
			flag = 1;
			if (a[l_].c != a[r_].c){
				ans += n_r;
			}
			r_--;
		}else{
			temp = n_r-n_l;
			flag = 0;
			if (a[l_].c != a[r_].c){
				ans += n_l;
			}
			l_++;
		}
	}
	
	cout << ans;
	
	return 0;
} 
