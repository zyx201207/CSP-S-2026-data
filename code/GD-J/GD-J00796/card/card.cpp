#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int q[500010],o;//队列 
int vis[300010];//是否有i 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			if(vis[a[j]]){
				
				o=vis[a[j]]; 
			}
			else {
				
				q[++o]=a[j];
				vis[a[j]]=o;
			}
		}
		for(int j=1;j<=o;j++){
			ans[q[j]]++;
		} 
		for(int j=1;j<=m;j++) {
			 vis[j]=0;
		}
		o=0;
	}
	for(int i=1;i<=m;i++){
		if(a[n]==i) cout<<n<<' ';
		else cout<<ans[i]<<' ';
	}
	return 0;
} 
