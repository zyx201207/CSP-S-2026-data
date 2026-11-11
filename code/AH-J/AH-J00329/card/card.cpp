#include<bits/stdc++.h>
using namespace std;
int n, m, p[500010], s[300010];
bool vis[300010];
stack<int> stk;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)scanf("%d", p + i);
	for(int i = 1;i <= n;i++){
		memset(vis, 0, sizeof(vis));
		for(int j = i;j <= n;j++){
			if(vis[p[j]]){
				while(stk.top() != p[j]){vis[stk.top()] = 0;stk.pop();}
				stk.pop();
			}else {vis[p[j]] = 1;stk.push(p[j]);}
		}
		while(!stk.empty()){s[stk.top()]++;stk.pop();}
	}
	for(int i = 1;i <= m;i++)printf("%d ", s[i]);
	return 0;
}
