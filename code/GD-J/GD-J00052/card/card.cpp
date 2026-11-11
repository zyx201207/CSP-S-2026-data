#include<bits/stdc++.h>
using namespace std;
int a[500005];
int zc[300005];
int dp[500005];
vector<int> v[500005];
int n,m;
void dfs(int x,int fa){
	dp[x]=1;
	for(int i:v[x]){
		if(i!=fa){
			dfs(i,x);
			dp[x]+=dp[i];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(zc[a[i]]==0){
			zc[a[i]]=i;
			if(i<n){
				v[i].push_back(i+1);
				v[i+1].push_back(i);
			}
		}else{
			v[i].push_back(zc[a[i]]);
			v[zc[a[i]]].push_back(i);
		}
	}
	dfs(n,0);
	for(int i=1;i<=m;i++){
		cout<<dp[zc[i]]<<" ";
	}
	return 0;
} 
