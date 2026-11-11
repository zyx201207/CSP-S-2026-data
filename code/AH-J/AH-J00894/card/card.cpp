#include <bits/stdc++.h>
using namespace std;
int a[200010];
int vis[200010];
int cnt[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int p=1;p<=n;p++){
		memset(vis,0,sizeof(vis));
		for(int i=p;i<=n;i++){
			if(vis[a[i]]==0){
				vis[a[i]]=i;
			}else{
				for(int j=vis[a[i]];j<=i-1;j++){
					vis[a[j]]=0;
				}
				vis[a[i]]=i;
			}
		}
		for(int i=p;i<=n;i++){
			if(vis[a[i]]>0){
				cnt[a[i]]++;
				vis[a[i]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
