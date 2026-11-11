#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	stack<int>sta;
	for(int k=1;k<=n;k++){
		memset(vis,false,sizeof(vis));
		for(int i=k;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=true;
				sta.push(a[i]);
			}else{
				while(sta.top()!=a[i]){
					vis[sta.top()]=false;
					sta.pop();
				}
			}
		}
		while(!sta.empty()){
			cnt[sta.top()]++;
			sta.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
}
