#include<bits/stdc++.h>
using namespace std;
long long c,t,d,n,sum,a[100005];
bool vis[100005];
void dfs(int x,int s){
	if(x==s||a[x+1]-a[x]>d){
		if(x==s) sum++;
		return ;
	}
	for(int i=x+1;i<=s;i++){
		
		if(a[i]-a[x]<=d&&vis[i]==0){
			vis[i]=1;
			dfs(i,s);
			vis[i]=0;
	    }
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				sum=0;
				vis[i]=1;
				dfs(i,j);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
