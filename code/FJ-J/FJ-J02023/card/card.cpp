#include<bits/stdc++.h>
#define N 500050
using namespace std;
int n,m,a[N],net[N],num[N];
vector<int>h[N]; 
bool v[N];
int dfs(int u){
	v[u]=1;
	int ans=0;
	for(int i=0;i<h[u].size();i++){
		ans+=dfs(h[u][i]-1);
	}
	num[a[u]]+=++ans;
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(net[a[i]]){
			h[net[a[i]]].push_back(i);
		}
		else if(i<n)h[i+1].push_back(i);
		net[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(!v[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
