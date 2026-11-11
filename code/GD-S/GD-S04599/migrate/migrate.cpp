#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,t,d,c,a[N]; 
int vis[N];
void dfs(int x,int end,int cnt){
	if(x>end) return ;
	if(x==end){
		vis[cnt]++;
		return;
	}
	for(int i=1;i<=d;i++){
		dfs(x+i,end,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0; 
		cin>>n>>d;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof vis);
				dfs(i,j,0);
				for(int k=1;k<=n;k++){
					if(vis[k]>0){
						if(vis[k]==2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
