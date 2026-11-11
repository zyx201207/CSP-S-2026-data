#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, cnt, ans, sum[N];
struct node{
	int id;
	int ai;
}a[N];
bool t[N], use[N];
stack<node> st;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cnt = n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i].ai);
		a[i].id = i;
	}
	while(cnt--){
		for(int i = 1; i <= n; i++){
			t[i] = false;
		}
		for(int i = n-cnt; i <= n; i++){
			if(use[i]) continue;
			if(!t[i] && !use[i]){
				st.push(a[i]);
				t[i] = true;
			}else if(!use[i] && t[i]){
				while((st.top().ai) != a[i].ai && !st.empty()){
					int tmp = st.top().id;
					t[tmp] = false;
					use[tmp] = true;
					st.pop();
				}
				int tmp1 = st.top().id;
				t[tmp1] = false;
				use[tmp1] = true;
				st.pop();
				st.push(a[i]);
				t[i] = true;
			}
		}
		/*ต๗สิ 
		while(!st.empty()){
			int mm = st.top().ai;
			
			cout << mm << ' ';
			st.pop();
		}
		cout << "\n";
		*/
		while(!st.empty()){
			node tmp3 = st.top();
			sum[tmp3.id]++;
			st.pop();
			if(st.empty()){
				use[tmp3.id] = true;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d ", sum[i]);
	}
	return 0;
}
//4 3 1 2 1 3    3 3 1 3 1 2 3 1
