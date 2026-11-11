#include<bits/stdc++.h>
using namespace std;
int ans=-1,n,m;
vector<int> a;
vector<bool> vis;
void dfs(int z,int k,int cnt){
	k=k&a[z];
	if(cnt==m){
		ans=max(ans,k);
		return;
	}
	vis[z]=1;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,k,cnt+1);
		}
	}
	vis[z]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push_back(t);
		vis.push_back(0);
	}
	sort(a.begin(),a.end(),[](int a,int b)->bool{return a>b;});
	for(int i=0;i<n;i++){
		dfs(i,INT_MAX,1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
