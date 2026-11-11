#include<bits/stdc++.h>
using namespace std;
int n,m,ans[5000005];
int a[500005];
bool vis[500005];
stack<int> sk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				sk.push(a[j]);
			}else while(sk.top()!=a[j]) sk.pop();
		}while(!sk.empty()){
			ans[sk.top()]++;
			sk.pop();
		}
	}for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
