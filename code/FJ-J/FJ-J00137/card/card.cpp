#include<bits/stdc++.h>
using namespace std;
int a[200010],pre[100010],n,m,ans[100010];
bool vis[310],flag=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
		vis[a[i]]=1;
	}
	memset(vis,0,sizeof(vis));
	if(n<=500 and m<=200){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]){
					for(int k=pre[a[j]];k<j;k++) vis[a[k]]=0;
				}
				vis[a[j]]=1;
				pre[a[j]]=j;
			}
			for(int j=1;j<=m;j++){
				if(vis[j]){
					ans[j]++;
					vis[j]=0;
				}
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(flag){
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<" ";
			}
		}
		return 0;
	}
}
