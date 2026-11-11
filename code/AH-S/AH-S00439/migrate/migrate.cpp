#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,dt,l;
long long ild[200005];
long long dp[200005];
void dfs(int x,int y){
	if(x==y){
		dp[l]=dt;
		l++;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if((ild[i]-ild[x])<=d){
			dt++;
			dfs(i,y);
			dt--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>ild[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j);
				
				sort(dp,dp+l);
				if(dp[0]==dp[1] and dp[1]!=dp[2]){
					ans++;
				}
				memset(dp,0,sizeof(dp));
				l=0;
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
