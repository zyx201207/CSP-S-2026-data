#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

signed main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> v;
	
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		ans.push_back(x);
	}
	
	int lg = 29;
	
	
	
	for(int c=lg;c>=0;c--){
		v.clear();
		
		for(auto t : ans){
			if((t >> c) & 1){
				v.push_back(t);
			}
		}
		
		if(v.size() >= m){
			ans = v;
		}
	}
	
	int sum = (1 << 30) - 1;
	
	for(auto t : ans){
		sum &= t;
	}
	
	cout << sum;
	
	return 0;
}

