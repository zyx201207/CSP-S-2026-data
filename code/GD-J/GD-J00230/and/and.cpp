#include<bits/stdc++.h>
using namespace std;
int n,m,vis[200005];
long long ans,a[200005]={0},b[200005]={0};
void dfs(int pos){
	if(pos==m+1){
		long long sum=b[1];
		for(int i=2;i<pos;i++){
			sum&=b[1];
		}
		if(sum>ans){
			ans=sum;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		
		}
		b[pos]=a[i];
		vis[i]=1;
		dfs(pos++);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];	
	}
	dfs(1);
	cout<<ans;
	return 0;
}
