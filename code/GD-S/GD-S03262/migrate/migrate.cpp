#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,x[N],vis[N];
void dfs(int en,int now,int cnt){
	if(now==en){
		vis[cnt]++;
		return ;
	}
	for(int i=now+1;i<=en;i++){
		if(x[i]-x[now]<=d){
			dfs(en,i,cnt+1);
		}
	}
}
void solve(){
	cin>>n>>d;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	if(c==11||c==12){
		long long k=d/(x[2]-x[1]);
		for(long long i=1;i<=n;i++){
			long long tmp=min(n,2*k-2+i)-k-i;
			ans+=max((long long)0,tmp);
		}
		cout<<ans<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=1;k<=n;k++){
					vis[k]=0;
				}
				dfs(j,i,0);
				for(int k=1;k<=n;k++){
					if(vis[k]!=0){
						if(vis[k]==2) ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
