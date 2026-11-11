#include"bits/stdc++.h"
using namespace std;
int n,m,a[500005],vis[300005],ans[300005];
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!s.empty()){
			s.pop();
		}
		for(int i=1;i<=m;i++)ans[i]+=vis[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
