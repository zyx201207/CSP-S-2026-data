#include <bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans[50005];
bool vis[50005];
stack <int> t;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				t.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(t.top()!=a[j]){
					t.pop();
				}
			}
		}
		while(!t.empty()){
			ans[t.top()]++;
			t.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
