#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;	
const int N = 3e5 + 10;
int n, m, t[N], a[N];
stack<int> st;
int ans[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 1; j <= n; j++){
		for(int i = j, x; i <= n; i++){
			x = a[i];
			if(t[x]){
				while(st.top() != x){
					t[st.top()] = 0;
					st.pop();
				}
			}
			else{
				st.push(x);
				t[x] = 1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			t[st.top()] = 0;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}

