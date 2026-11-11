#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000010];
int cnt=0;
int i,j;
void dfs(int now){
	if(now==n+1){
		cnt+=1;
		return;
	}
	for(int l=1;l+now<=n&&l<=d;l++){
		dfs(l+now);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				dfs(i);
				if(cnt==2){
					ans+=1;
				}
				cnt=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
