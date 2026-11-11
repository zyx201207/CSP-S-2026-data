#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10, M = 3e5+10;
int ans[M], n, m, a[N];
void slove(int turn, int a[]){
	int ton[M];
	memset(ton, 0, sizeof(ton));
	stack<int> st;
	for(int i = turn;i <= n;i ++){
		if(ton[a[i]]){
			while(st.size() && st.top() != a[i]){
				ton[st.top()] --;
				st.pop();
			}
		}else{
			ton[a[i]] ++;
			st.push(a[i]);
		}
	}
	while(st.size()){
		ans[st.top()] ++;
		st.pop();
	}
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		slove(i, a);
	}
	for(int i = 1;i <= m;i ++){
		cout << ans[i] << ' ';
	}
	return 0;
}
