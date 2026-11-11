#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int vis[300005];
int id[300005];
int ans[300005];
int c[5000005];
bool f1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i]!=a[i]) f1=1;
	}
	if(!f1){
		for(int i=1;i<=n;i++){
			int len1=0;
			memset(vis,0,sizeof(vis));
			memset(b,0,sizeof(b));
			memset(id,0,sizeof(id));
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					b[++len1]=a[j];
					vis[a[j]]=1;
					id[a[j]]=len1;
				}
			}
			for(int j=1;j<=m;j++){
				if(vis[j]){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		int len1=0;
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		memset(id,0,sizeof(id));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				b[++len1]=a[j];
				vis[a[j]]=1;
				id[a[j]]=len1;
			}
			else{
				for(int k=id[a[j]];k<=len1;k++){
					vis[b[k]]=0;
				}
				len1=id[a[j]]-1;
				id[a[j]]=len1+1;
				b[len1+1]=a[j];
				vis[a[j]]=1;
				len1++;
			}
		}
		for(int j=1;j<=m;j++){
			//cout<<j<<" "<<ans[j]<<endl;
			if(vis[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
