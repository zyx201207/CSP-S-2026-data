#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using numtype = int;

numtype n, m;

inline void solve(vector<numtype>& arr, vector<numtype>& ans, numtype beg){
	vector<bool> app(m, false);
	stack<numtype> stk;
	
	for (numtype i = beg; i < n; ++i){
		if (app[arr[i]]){
			while (stk.top() != arr[i]){
				app[stk.top()] = false;
				stk.pop();
			}
		}
		else{
			stk.push(arr[i]);
			app[arr[i]] = true;
			//cerr << "sda\n";
		}
		
		//for (bool p : app) cerr << p << " ";
		//cerr << "\n";
	}
	
	for (numtype j = 0; j < m; ++j){
		
		if (app[j]) ++ans[j];
	}
	//cerr << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	vector<numtype> arr(n, 0);
	for (numtype i = 0; i < n; ++i){
		cin >> arr[i];
		--arr[i];
	}
	
	vector<numtype> ans(m, 0);
	
	for (numtype i = 0; i < n; ++i){
		solve(arr, ans, i);
	}
	
	for (numtype j = 0; j < m; ++j){
		cout << ans[j] << " ";
	}
	
	return 0;
}
