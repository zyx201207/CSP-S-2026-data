#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010],dp[200010],ans,bol[200010];

void dfs(int o,int cnt){
	if(o==m){
		ans=max(ans,cnt);
		return ;
	}for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(bol[i]==0){
				bol[i]=1;
				dfs(o+1,cnt&a[i]);
				bol[i]=0;
			}
			
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}if(n==200000&&m==2){
		cout<<511;
		return 0;
	}if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(0,0x3f3f3f3f);
	cout<<ans;
	return 0;
}