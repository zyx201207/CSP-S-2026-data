#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int c,t,x[N],n,d,mi=N,ans=0,cnt;
void dfs(int p,int ed,int sum){
	if(p==ed){
		cout<<sum<<" ";
		mi=min(mi,sum);
		return ; 
	}
	for(int i=p+1;i<=n;i++){
		if(x[i]-x[p]>d) {
			break;
		}
		dfs(i,ed,sum+1);
	}
}
void dfs2(int p,int ed,int sum){
	if(p==ed){
		if(mi==sum){
			cnt++;
			return;
		}
		return ; 
	}
	for(int i=p+1;i<=n;i++){
		if(x[i]-x[p]>d) {
			break;
		}
		dfs2(i,ed,sum+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mi=N,cnt=0;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
