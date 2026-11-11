#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n;
	cin >> m;
	int a[500005] = {};
	int tong[500005] = {};
	int first[500005] = {};
	int cnt[500005] = {};
	stack<int> st;
	int tail = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		for(int j = m; j <= n; j++){
			st.push(a[j]);
			bool flag = true;
			tong[a[j]]++;
			if(tong[a[j]] == 1) first[a[j]] = i;
			for (int k = 1; k <= m; k++){
				if(tong[k] == 2){
					flag = false;
					break;
				}
			}
			if(!flag){
				while(st.top() != a[j]){
					st.pop();
				}
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << cnt[i] <<" ";
	}
	return 0;
} 
