#include<bits/stdc++.h>
using namespace std;
int t,c;
int n,d,zd;
int a[122222];
int ans=200000000000000000,ans1=1,ans2;
void dfs(int u,int s,int as){
	if(u>zd){
		if(as==ans){
			ans1+=1;
		}else if(as<ans){
			ans1=1;
			ans=as;
		}
		return;
	}
	dfs(u+1,a[u+1]-a[u],as+1);
	if(s+a[u+1]-a[u]<=d){
		dfs(u+1,s+a[u+1]-a[u],as);
	}
}
void sv(){
	ans1=1;
	ans=200000000000000000;
	ans2=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			zd=j;
			dfs(i,0,1);
			if(ans1==2){
				ans2++;
			}		
			
		}
	}
	cout<<ans2<<'\n';
	return;
}
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sv();
	}
	return 0;
} 
