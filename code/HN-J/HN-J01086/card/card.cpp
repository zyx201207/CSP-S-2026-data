#include<bits/stdc++.h>
using namespace std;
int n,m,a[300300];
bool vis[300300];
int ans[300300];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int k=1;k<=n;k++){
		while (!s.empty()) s.pop();
		memset(vis,false,sizeof(vis));
		for (int i=k;i<=n;i++){
			if (vis[a[i]]){
				while (s.top()!=a[i]){
					vis[s.top()]=false;
					s.pop();
				}
			}
			else{
				vis[a[i]]=true;
				s.push(a[i]);
			}
		}
		for (int i=1;i<=m;i++){
			if (vis[i]) ans[i]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

