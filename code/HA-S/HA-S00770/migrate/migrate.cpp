#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10005],a[10005];
void dfs(int cnt,int sum){
	int p=1;
	if(cnt!=1){
		for(int i=1;i<=n;i++){
			if(sum==x[i]){
				p=0;
				break;
			}	
		}
		if(p){
			return ;
		}
	}
	
	if(cnt==d+1){
		a[sum]+=1;
		return ;
	}
	for(int i=cnt;i<=n;i++){
		for(int j=1;j<=d;j++){
			
			dfs(cnt+1,sum+j);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		dfs(1,x[1]);
		for(int i=x[1];i<=x[n];i++){
			if(a[i]==2){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
