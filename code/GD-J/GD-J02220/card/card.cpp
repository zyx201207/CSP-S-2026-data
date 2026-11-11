#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 1;
const int inf = 0x3f3f3f3f;
int len[N];
int ans[N];
int a[N];
signed main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	stack<int> st;
	for(int i = 1 ; i <= n ; i ++){
		memset(len , 0 , sizeof(len));
		for(int j = i ; j <= n ; j ++){
			st.push(a[j]);
			len[a[j]] ++;
		}
		for(int j = i ; j <= n ; j ++){
			if(!len[a[j]]){
				st.push(a[j]);
				len[a[j]] ++;
			}else{
				while(len[a[j]] > 0){
					int u = st.top();
					st.pop();
					len[u] --;
				}
				len[a[j]] ++;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			int u = st.top();
			st.pop();
			ans[u] ++;
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		cout << ans[i] << " ";
	}
	return 0;
} 
