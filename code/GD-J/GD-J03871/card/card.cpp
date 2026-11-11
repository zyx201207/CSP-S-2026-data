#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[200010];
bool vis[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				st.push(a[j]);
				vis[a[j]]=1;
				continue;
			}
			while(st.top()!=a[j]&&!st.empty()){
				vis[st.top()]=0;
				st.pop();
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
