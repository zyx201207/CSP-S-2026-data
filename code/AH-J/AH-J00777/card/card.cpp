#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long a[N],b[N],ans[M],vis[M],tot=0;
long long n,m;
void solve(){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>1000){ solve();return 0; }
	for(int i=1;i<=n;i++){
		tot=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			b[++tot]=a[j];
			for(int k=1;k<tot;k++){
				if(b[k]==a[j]){ tot=k;break; }
			}
		}
		for(int k=1;k<=tot;k++) vis[b[k]]=1;
		for(int k=1;k<=m;k++){
			if(vis[k]==1) ans[k]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
