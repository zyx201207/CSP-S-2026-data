#include <bits/stdc++.h>
using namespace std;
#define ll long long
int vis[200005],rd[5005];
ll a[200005];
int n;
ll d;
void dfs(int x,int r,int cnt){
	if(x==r){
		if(cnt<rd[r]){
			rd[r]=cnt;
			vis[r]=1;
		}
		else if(cnt==rd[r]){
			vis[r]++;
		}
	}
	for(int i=x+1;i<=r;i++){
		if(a[i]-a[x]>d)break;
		dfs(i,r,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(rd,0x3f,sizeof(rd));
			for(int j=i;j<=n;j++){
				dfs(i,j,0);
			}
			for(int j=1;j<=5000;j++){
				if(vis[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

