#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
int c,t,n,d,a[N],nxt[N],f[N],g[N],vis[N];
queue<int>q,p;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int l=i+1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[i]+d>=a[mid]){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			nxt[i]=l-1;
//			cout<<i<<" "<<nxt[i]<<"?\n";
		}
		long long ans=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			while(!q.empty())q.pop();
			while(!p.empty())p.pop();
			q.push(i);
			f[i]=1;
			while(!q.empty()){
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(int j=u+1;j<=nxt[u];j++){
						if(vis[j]!=i){
							vis[j]=i;
							g[j]=0;
							p.push(j);
						}
						g[j]+=f[u];
					}
				}
				while(!p.empty()){
					int u=p.front();
					p.pop();
					if(g[u]==2){
						ans++;
					}
					if(g[u]<=2){
						q.push(u);
						f[u]=g[u];
//						cout<<i<<" "<<u<<" "<<f[u]<<"??\n";
					}
				}
//				cout<<!q.empty()<<"????????\n";
			}
		}
		cout<<ans<<"\n";
	}
}
