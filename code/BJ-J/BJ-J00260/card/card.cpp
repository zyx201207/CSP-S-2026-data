#include <bits/stdc++.h>
using namespace std;
int a[500050],dp[500050],ne[500050],la[300050],num[500050];
bool adnum[500050];
int ans[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int xs=1;xs<=n;xs++){
		cin>>a[xs];
		ne[la[a[xs]]]=xs;
		la[a[xs]]=xs;
	}
	for(int xs=n;xs>0;xs--){
		num[xs]=1;
		if(ne[xs]>0){
			dp[xs]=ne[xs];
		}else{
			dp[xs]=xs+1;
			adnum[xs]=1;
		}
	}
	for(int xs=1;xs<=n;xs++){
		if(adnum[xs]){
			ans[a[xs]]+=num[xs];
		}
		num[dp[xs]]+=num[xs];
	}
	for(int xs=1;xs<=m;xs++){
		cout<<ans[xs]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
