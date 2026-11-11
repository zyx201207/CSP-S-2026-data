#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
stack<int> stk;
int a[500010],in[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if (in[a[j]])
				while (stk.top() != a[j]){
					in[stk.top()] = 0;
					stk.pop();
				}
			else{
				in[a[j]] = 1;
				stk.emplace(a[j]);
			}
		}
		while (stk.size()){
			ans[stk.top()]++;
			stk.pop();
		}
		for (int i = 1;i <= m;i++)
			in[i] = 0;
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
