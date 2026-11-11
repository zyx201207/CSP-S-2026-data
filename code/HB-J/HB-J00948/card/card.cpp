#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],t[500001],book[500001];
vector<int> dp[500002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(book[a[i]]==0){
			dp[i]=dp[i+1];
			dp[i].push_back(a[i]);
		}
		else{
			dp[i]=dp[book[a[i]]];
			dp[book[a[i]]].erase(dp[book[a[i]]].begin(),dp[book[a[i]]].end());
		}
		book[a[i]]=i;
		for(int j=0;j<int(dp[i].size());j++) t[dp[i][j]]++;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}

