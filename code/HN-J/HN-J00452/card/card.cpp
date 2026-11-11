// 模拟策略？算了，模拟打一波 
#include<bits/stdc++.h>
using namespace std;

int read() {
	int x = 0, f = 1;
	int c = getchar();
	while(c != EOF && !('0' <= c && c <= '9')) {
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c != EOF && ('0' <= c && c <= '9')) {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	
	return x * f;
} 
// 完成于 10 : 56 
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n = read();
	int m = read();
	vector<int> a(n);
	vector<int> t(m);
	for(int i = 0; i < n; i++) {
		a[i] = read();
	}
	
	for(int i = 0; i < n; i++) {
		vector<char> in(m, false); 
		stack<int> stk;
//		cout << "#" << i << endl;
		for(int j = i; j < n; j++) {
			int val = a[j];
			if(in[val]) {
//				cout << val << "清空："; 
				while(!stk.empty()) {
					int v = stk.top();
					stk.pop();
//					cout << v << " "; 
					in[v] = false;
					if(v == val) break;
				}
//				cout << stk.size() << endl;
			}
			stk.push(val);
			in[val] = true;
		}
		while(!stk.empty()) {
			t[stk.top() - 1]++;
			stk.pop();
		}
	}
	for(auto& x : t) {
		cout<<x<<" ";
	}
	return 0;
}
