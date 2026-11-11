#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[5010];
int cnt[11],ans=0;

void dfs(int i,int j,int times){
	if(i==j){
		cnt[times]++;
		return;
	}
	for(int k=i+1;k<=j;k++){
		if(x[k]-x[i]<=d){
			dfs(k,j,times+1);
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(cnt,0,sizeof(cnt));
				dfs(i,j,1);
				for(int k=1;k<=n;k++){
					if(cnt[k]==1) break;
					if(cnt[k]>1){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
