#include <bits/stdc++.h>
using namespace std;
int cnt[300005];
int n,m;
int a[500005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		int buk[300005] = {0};
		for (int j = i;j <= n;j++){
			if (buk[a[j]]){
//				cout << 1 << endl;
				while (st.top() != a[j]){
					buk[st.top()]--;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				buk[a[j]]++;
			}
//			for (int i = 1;i <= m;i++){
//				cout << buk[i] <<' ';
//			}
//			cout << endl;
		}
		while (!st.empty()){
			cnt[st.top()]++;
//			cout << st.top() << ' ';
			st.pop();
		}
//		cout << endl;
	}
	for (int i = 1;i <= m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
} 
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
