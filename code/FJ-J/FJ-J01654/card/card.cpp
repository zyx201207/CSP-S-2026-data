#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500006],st[500006],viss[500006],vis[500006],k[500006],ans[500006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		viss[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]>0)vis[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>1){
				long long kk=j;
				while(a[kk-1]!=a[j]){
					if(vis[a[kk]]>0)st[a[j]]--;
					kk--;
				}
			}else{
				st[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(st[j])ans[j]++;
		}
		for(int q=1;q<=m;q++){
			k[q]=0;st[q]=0;vis[q]=0;
		}
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++){
		if(viss[i]>0)cout<<ans[i]<<' ';
	}
	return 0;
}
