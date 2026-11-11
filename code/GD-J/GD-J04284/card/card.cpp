#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
signed main() {//±©Á¦Ä£Äâ£¬O(n^2+m)×óÓÒ
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=0; i<n; i++) {
		stack<int> st;
		bool vis[300005];
		memset(vis,0,sizeof(vis));
		for(int j=i+1; j<=n; j++) {
			if(!vis[a[j]]) st.push(a[j]),vis[a[j]]=1;
			else while(st.top()!=a[j]) st.pop();
		}
		while(!st.empty()) {
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1; i<=m; i++) cout<<cnt[i]<<" ";
	return 0;
}
