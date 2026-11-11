#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],ins[M],ans[M],A = 1;
stack<int> stk;

void solvea(){
	a[n+1] = INT_MAX;
	int id = 0;
	for (int i = 1;i <= n;i++) if (a[i] < a[i+1]) ans[++id] = i;
	return;
}

void solve(){
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if (ins[a[j]]){
				while (stk.top() != a[j]){
					int t = stk.top();
					ins[t] = 0;
					stk.pop();
				}
			} else stk.push(a[j]),ins[a[j]] = 1;
		}
		for (int j = 1;j <= m;j++) ans[j] += ins[j];
		while (stk.size()) ins[stk.top()] = 0,stk.pop();
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		A &= (a[i] >= a[i-1] ? 1 : 0);
	}
	if (A) solvea();
	else solve();
	for (int i = 1;i <= m;i++) cout<<ans[i]<<' ';
	return 0;
}
