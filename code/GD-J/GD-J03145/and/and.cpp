#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<int> vec;

inline int quick_pow(int a , int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	return res;
}

int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	int n , m; cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int input;
		cin >> input;
		vec.push_back(input);
	}
	
	for(int i = 30;i >= 0;i--){
		vector<int> tmp;
		for(int j : vec){
			if((j >> i) & 1) tmp.push_back(j); 
		}
		
		if(tmp.size() >= m) vec = tmp;
		if(vec.size() == m) break; 
	}
	
	int ans = quick_pow(2,30) - 1;
	for(int i : vec){
		ans = ans & i;
	}
	cout << ans << endl;
	
	return 0;
}
