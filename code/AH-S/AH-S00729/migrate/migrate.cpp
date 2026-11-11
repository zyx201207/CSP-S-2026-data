#include<bits/stdc++.h>
using namespace std;
//±©ËÑ£¬¸´ÔÓ¶È·ÖÎö£ºn^3 ~ n! 
int c,t,n,d;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long a[505],g[505][505],f[505][505],vis[505];
int dfs(int id,int step,long long tu,long long tw){
	if(id==tu){
		if(step==tw){
			return 1;
		}
		return 0;
	}
	if(step>tw){
		return 0;
	}
	int ret=0;
	for(int i=1;i<=n;i++){
		if(g[id][i] && !vis[i]){
			vis[i]=true;
			ret+=dfs(i,step+1,tu,tw);
			vis[i]=false;
		}
	} 
	return ret;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=abs(a[i]-a[j])<=d?1:0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=f[j][i]=(g[i][j]?1:inf);
			}
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[j][i]=f[i][k]+f[k][j];
					}
				}
			}
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[i]=true;
				if(dfs(i,0,j,f[i][j])==2){
					ans++;
				}
				vis[i]=false;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
