#include <bits/stdc++.h>
using namespace std;
stack<int> k;
int n,m;
int a[500005],ans[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(k.top()!=a[j]) vis[k.top()]=0,k.pop();
				k.pop();
			} 
			else vis[a[j]]=1;
			k.push(a[j]);
		}
		while(!k.empty()){
			ans[k.top()]++;
			k.pop();
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++) cout << ans[i] << ' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
