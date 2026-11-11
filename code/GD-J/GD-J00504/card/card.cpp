#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <stack>
using namespace std;

const int N = 500005,M = 300005;
#define pii pair<int,int>
int n,m;
int a[N];
int lst[M],to[N];
int ans[M];
int pre[N];
int dep[N];
struct BIT{
	int tr[N];
	#define lowbit(x) (x & -x)
	void add(int x,int y){while(x <= n) tr[x] += y,x += lowbit(x);}
	void add(int l,int r,int v){add(l,v),add(r,-v);}
	int ask(int x,int y = 0){while(x) y += tr[x],x -= lowbit(x);return y;}
}T;
int s[N];
bool vis[N];
stack<int> qu;
void brute(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++) vis[j] = 0;
		while(qu.size()) qu.pop();
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(1){
					if(qu.top() == a[j]) break;
					vis[qu.top()] = 0;
					qu.pop();
				}
			}
			else qu.push(a[j]),vis[a[j]] = 1;
		}
		for(int j = 1;j <= m;j++) vis[j] = 0;
		while(qu.size()) vis[qu.top()] = 1,qu.pop();
		for(int j = 1;j <= m;j++) ans[j] += vis[j];
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	bool flg = 1;
	for(int i = 1;i <= n;i++) cin >> a[i],flg = flg && (a[i-1] <= a[i]);
	// int last = 0;
	for(int i = n;i >= 1;i--){
		// add : (i,lst[i])
		if(lst[a[i]]){
			to[i] = lst[a[i]];
			if(to[i] != i + 1){
				for(int j = to[i];j <= n;j++)
					if(to[j]){ pre[j] = i;break; }
			}
			// last = i;
		}
		lst[a[i]] = i;
	}
	if(!flg) return brute(),0;
	for(int i = 1;i <= n;i++) s[i] = s[i-1] + (to[i] > 0);
	for(int i = 1;i <= n;i++){
		if(!to[i]) continue;
		if(!pre[i]) dep[i] = 1;
		else dep[i] = dep[pre[i]] + 1;
		T.add(i,to[i],(dep[i] + 1) >> 1);
		if((dep[i] & 1) == 0) T.add(i,to[i],s[i - dep[i]]);
	}
	// for(int i = 1;i <= n;i++) cerr << T.ask(i) << ' ';
	for(int i = n;i >= 1;i--) ans[a[i]] = max(ans[a[i]],i - T.ask(i));
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}