#include<bits/stdc++.h>
using namespace std;
int dp[500005];
int lst[500005];
int id[500005];
int a[500005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(!id[a[i]]){
			id[a[i]]=i;
		}
		else{
			lst[i]=id[a[i]];
		}
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(lst[i]){
			dp[lst[i]]+=dp[i];
		}
		else{
			dp[i+1]+=dp[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp[id[i]]<<" ";
	}
	return 0;
}
