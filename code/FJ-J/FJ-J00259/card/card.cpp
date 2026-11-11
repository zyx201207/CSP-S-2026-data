#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;
int n, m;
int a[500005], b[300005];
int num[300005];
void solve(int x){
	stack<int> st;
	for(int i = 1; i <= 300002; i++) num[i] = 0;
	for(int i = n; i >= x; i--){
		if(num[i] == 0){
			st.push(a[i]);
			num[a[i]] = 1;
		}else{
			while(!st.empty()&&st.top() != a[i]){
				num[st.top()] = 0;
				st.pop();
			}
			if(st.empty()) st.push(a[i]), num[a[i]] = 1;
		}
	}
	while(!st.empty()){
		b[st.top()]++;
		st.pop();
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		solve(i);
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << ' ';
	}
	return 0;
}
