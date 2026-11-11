#include <bits/stdc++.h>
using namespace std;
stack<int> s;
bool b[300005];
int n,m,ans[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i < n;i++){
		for (int j = i;j <= n;j++){
			if (b[a[j]]){
				while(s.top() != a[j]){
					b[s.top()] = false;
					s.pop();
				}
			}else{
				s.push(a[j]);
				b[a[j]] = true;
			}
		}
		while (!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i = 1;i <= m;i++)
		cout << ans[i] << endl;
	return 0;
}
