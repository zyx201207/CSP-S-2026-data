#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],wz[M],ans[M],vis[M],dp[N];
vector<int>l[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!wz[a[i]]){
			wz[a[i]]=i;
			continue;
		}
		for(int j=i+1;j<wz[a[i]];j++){
			l[j].push_back(i);
		}
		wz[a[i]]=i;
	}
	for(int i=1;i<=n;i++)dp[i]=i;
	for(int i=1;i<=n;i++){
		for(int j : l[i]){
			dp[i]-=dp[j];
		}
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]])continue;
		ans[a[i]]=dp[i];
		vis[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
