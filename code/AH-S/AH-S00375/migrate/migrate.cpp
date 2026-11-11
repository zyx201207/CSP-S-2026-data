#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int dfs(int u,int v,int h,int n,int d){
	if(u>v||h==0) return 0;
	if(h==0&&u==v) return 1;
	int ans=0;
	for(int i=u+1;i<=upper_bound(x+1,x+n+1,x[i]+d)-x-1;i++)
		ans+=dfs(i,v,h-1,n,d);
	return ans;
}
int tt(int u,int v,int n,int d){
	int h=0;
	for(int i=u;i<=v;){
		i=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		h++;
	}
	int p=dfs(u,v,h,n,d);
	if(p==2) return 1;
	else return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i<=d) continue;
				ans+=tt(i,j,n,d);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
