#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2100000];
vector<int>e[5050];
int dis[5050],vis[5050],vis2[5050],cn[5050];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=5000){
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				e[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						e[i].push_back(j);
						e[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++){
				queue<int>q;
				vis[i]=1;
				cn[i]=1;
				q.push(i);
				while(!q.empty()){
					int x=q.front();
					q.pop();
					vis2[x]=1;
					if(cn[x]>3)cn[x]=3;
					for(int y:e[x]){
						if(!vis2[y]){
							if(!vis[y]){
								vis[y]=1;
								dis[y]=dis[x]+1;
								q.push(y);
							}
							if(dis[y]==dis[x]+1){
								//cerr<<x<<' '<<y<<endl;
								cn[y]+=cn[x];
							}			
						}
					}
				}
				for(int j=1;j<=n;j++){
					if(cn[j]==2)ans++;
					//cout<<cn[j]<<' ';
				}//cout<<endl;
				for(int j=1;j<=n;j++){
					dis[j]=vis[j]=vis2[j]=cn[j]=0;
				}
			}
			cout<<ans/2<<endl;
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int stp=d/(a[2]-a[1]);
			if(stp>1)cout<<max(n-(stp*2-1),0ll)<<endl;
			else cout<<0<<endl;
		}

	}
	return 0;
}
