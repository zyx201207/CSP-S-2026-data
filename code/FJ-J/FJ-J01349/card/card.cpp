#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int n,m,a[N],ans[N],vis[N],d[N],vv[N],tot[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i;i--){
		int now=a[i];
		if(!vis[a[i]]) vis[now]=i,d[i]=i+1,vv[i]=now,tot[i]=1;
		else d[i]=vis[now],vv[i]=0,tot[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(vv[i]) ans[vv[i]]+=tot[i];
		tot[d[i]]+=tot[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";cout<<endl;
}
