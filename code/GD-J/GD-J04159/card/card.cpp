#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[300010]{},f[500010]{};
bool vis[300010]{};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		f[i]=x;	
	}
	for(int i=1;i<=n;i++){
		stack<int>a;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[f[j]]){
				while(a.top()!=f[j]){
					vis[a.top()]=0;
					a.pop();
				}						
			}
			a.push(f[j]);			
			vis[f[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j])sum[j]++;
		}	
	}
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
	return 0;
} 

