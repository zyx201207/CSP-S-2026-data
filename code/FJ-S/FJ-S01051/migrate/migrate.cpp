#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3;
const int inf=1e18;
int c,t,n,d;
int a[N+5];
vector<int> g[N+5];
int vis[N+5];
int minn=2e9;
int cnt=0;
int hh[N+5],hs=0; 
void dfs(int end,int s,int num,int h){//s当前下标，num飞的次数 
	if(s==end){
		h=h*10+s;
		if(num<minn){
			cnt=1;
			minn=num;
			memset(hh,0,sizeof hh);
			hs=0;
			hh[hs]=h;
		}
		if(num==minn){
			int fff=1;
			for(int i=0;i<hs;i++){
				if(hh[i]==h)fff=0; 
			}
			if(fff){
				hh[++hs]=h;
				cnt++;
			}
		} 
		return;
	}
	if(s>end)return;
	for(int i=0;i<g[s].size();i++){
		//vis[g[s][i]]=1;
		dfs(end,g[s][i],num+1,h*10+g[s][i]);
		//vis[g[s][i]]=0;
	} 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			int ans=0;
			for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int p=abs(a[j]-a[i]);
				if(p<=d)g[i].push_back(j);
			}
		    }
		    for(int i=1;i<=n;i++){
		    	for(int j=i+1;j<=n;j++){
		    		minn=2e9;cnt=0;
		    		memset(vis,0,sizeof vis);
		    		dfs(j,i,0,i);
		    		if(cnt==2){
		    			ans++;
		    			cnt=0;
					}
				}
			}
			cout<<ans<<"\n";		 		
	}
	return 0;
}
