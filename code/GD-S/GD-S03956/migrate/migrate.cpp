#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
void dfs_mn(int idx,int cnt,const int &n,vector<bool>&vis,const vector<int>&x,vector<vector<int> >&mn,const int st){
	if(idx!=st) mn[st][idx]=min(mn[st][idx],cnt);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs_mn(i,cnt+abs(x[idx]-x[i]),n,vis,x,mn,st); 
		}
	}
}
void dfs(int idx,int cnt,const int &st,string s,const int &n,vector<int>&vis,const vector<int>&x,const vector<vector<int> >&mn,int &ans){
	if(mn[st][idx]==cnt&&vis[idx]==1){
		vis[idx]=4;		vis[idx]=4;
	}
	else if(mn[st][idx]==cnt&&vis[idx]==4){
		vis[idx]=2;
		ans++;
	}      
	else if(mn[st][idx]==cnt&&vis[idx]==2){
		vis[idx]=3;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,cnt+abs(x[idx]-x[i]),st,s+=char(i+'0'),n,vis,x,mn,ans);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>x(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>x[i]; 
		}
		vector<vector<int> >mn;
		mn.resize(5100,vector<int>(n+1,1e9));
		for(int i=1;i<=n;i++){
			vector<bool>vis(n+1,0); 
			vis[i]=1;
			dfs_mn(i,0,n,vis,x,mn,i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<int>vis(n+1,0); 
			vis[i]=1;
			dfs(i,0,i,"",n,vis,x,mn,ans);
		}
		cout<<ans<<"\n";
	} 
	return 0;
}

