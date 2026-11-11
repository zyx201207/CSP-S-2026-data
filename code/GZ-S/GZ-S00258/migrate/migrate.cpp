//GZ-S00258 ³Â±òˆ 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
bool vis[N];
int ans=0;
int n,d;
int a[N];
int mi=-1;
void dfs(int dao,int step){
	if(dao>n) return;
	if(vis[dao]==1){
		if(mi==step){
			ans++;
		}else if(mi>step){
			mi=step;
			ans=0;
		}
	} else{
		for(int i=1;i<=d;i++){
			vis[dao+d]=1;
			dfs(d+dao,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(1,0);
		cout<<ans;
	}
	return 0;
} 
