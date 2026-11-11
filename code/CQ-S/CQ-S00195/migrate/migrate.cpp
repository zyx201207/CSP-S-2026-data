#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[100005],cnt,l,ans;
void dfs(int k,int m,int p){
	if(p>cnt) return ;
	if(k==m){
		if(p<cnt) cnt = p,l = 1;
		else l++;
	}
	for(int i=k+1;i<=m;i++){
		if(a[i]-a[k]>d) return ;
		dfs(i,m,p+1);
	} 
}
signed main(){
	//printf
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt = 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt = 1e9,l = 0;
				dfs(i,j,0);
				if(l==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
