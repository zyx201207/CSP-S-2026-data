#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int ton[N];	//存答案
int a[N];
//int a[N];	//存某位置的值
//int top = 1;	//指向最高位 
int n, m;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vector<int> b;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		b.push_back(t);
	}
	
	for(int i = 1; i <= n; i++){
		stack<int> stk;
		for(int j = i; j <= n; j++){
//			cout << "y";
			if(a[b[j-1]] == 1){
				while(stk.size() > 0){
					a[stk.top()] = 0;
					stk.pop();
					if(stk.top() == b[j-1]){
						break;
					}
				}
//				cout << "y";
			}else{
				a[b[j-1]] = 1;
				stk.push(b[j-1]);
			}
//			cout << "y";
		}
//		cout << "y";
		for(int j = 0; j < stk.size(); j++){
			ton[stk.top()]++;
			a[stk.top()] = 0;
			stk.pop();
		}
//		cout << "y";
	}
//	cout << "y";
	for(int i = 1; i <= m; i++){
		cout << ton[i] << " ";
	}
//	cout << m;
	return 0;
}
