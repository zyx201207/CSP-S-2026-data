#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y; 
};
int n,d,vis[20001],viss[20001];
void bfs(int st,int ed,int step,vector<int>a[20001]){
	if(st==ed){
		viss[step]++;
		return ;
	}for(auto i:a[st]){
		if(vis[i]==0){
			vis[i]=1;
			bfs(i,ed,step+1,a);
			vis[i]=0;
		}
	}
}void solve(){
	int x[20001],ans=0;
	vector<int>a[20001]={};
	cin>>n>>d;
	memset(vis,0,sizeof vis);
	memset(viss,0,sizeof viss);
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				a[x[i]].push_back(x[j]);
				a[x[j]].push_back(x[i]);
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<x[i]<<" "<<x[j]<<"  ";
			memset(viss,0,sizeof viss);
			memset(vis,0,sizeof vis);
			vis[x[i]]=1;
			bfs(x[i],x[j],0,a);
			vis[x[i]]=0;
//			for(int i=1;i<=n;i++)cout<<viss[i]<<" ";
//			cout<<endl;
			for(int i=1;i<=n;i++){
				if(viss[i]!=0){
					if(viss[i]==2){
						ans++;
						break;
					}else break;
				}
			}
		}
	}
    cout<<ans<<endl;
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
//	t=1;
	while(t--){
		solve();
	}return 0;
}
