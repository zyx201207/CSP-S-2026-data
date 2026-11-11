#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005],pos[500005];
stack<int> stk;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int _=1;_<=n;_++){
		memset(pos,0,sizeof(pos));
		for (int i=_;i<=n;i++){
			if (pos[a[i]]==0){
				stk.push(a[i]);
				pos[a[i]]++;
			}else{
				while (!stk.empty() && stk.top()!=a[i]){
					pos[stk.top()]=0;
					stk.pop();
				}
				if (!stk.empty()){
					pos[stk.top()]=0;
					stk.pop();
				}
				stk.push(a[i]);
				pos[a[i]]++;
			}
		}
		while (!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
