#include<bits/stdc++.h>
using namespace std;
bool vis[5005];
int n,m,ans[5005],a[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		stack<int> st;
		for(int j = i;j <= n;j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]] = true;
			}else{
				while(true){
					int x = st.top();st.pop();
					if(x == a[j]){
						st.push(a[j]);
						break;
					}else vis[x] = false;
				}
			}
		}
		for(int i = 1;i <= m;i++)
			if(vis[i]) ans[i]++;
		memset(vis,0,sizeof(vis));
	}
	for(int i = 1;i <= m;i++) cout<<ans[i]<<" ";
	return 0;
} 
