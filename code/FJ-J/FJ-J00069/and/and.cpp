#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=-1e18;
int n,m;
bool vis[200005];
void dfs(long long sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(sum&a[i],cnt+1);
			vis[i]=false;
		}
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(((1<<30)-1),0);
	cout<<ans<<endl;
	return 0;
} 
