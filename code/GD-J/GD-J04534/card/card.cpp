#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
using namespace std;
const int N = 5e5 + 9;
int a[N];
using ll = long long;
set<int>last[N];
ll cnt[N],tmp[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin >> n >> m;
	_for(i,1,n) cin >> a[i];
	_for(cur,1,n){
		_for(i,1,m)last[i].clear();
		stack<int>stk;
		_for(i,cur,n) {
			int x = a[i];
			if(!last[x].empty()){
				int lim = *last[x].rbegin();
				int d; 
				do{
					d = stk.top();
					last[a[d]].erase(d);
					stk.pop();
				}while(d != lim); 
			}
			
			stk.push(i);
			last[x].insert(i);
		}
		while(!stk.empty())cnt[a[stk.top()]] ++,stk.pop();
	}
	_for(i,1,m) cout << cnt[i] << ' '; cout << '\n';
	return 0;
} 
