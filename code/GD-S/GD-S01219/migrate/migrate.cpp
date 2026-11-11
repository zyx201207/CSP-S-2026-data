#include<bits/stdc++.h>
#define int long long
using namespace std;
int op,t,n,d,ans,a[2000005],dis[2000005],f[2000005];
bool bj[2000005]; 
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>op>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
				f[j]=0;
				bj[j]=0;
			}
			queue<int> q;
			bj[i]=1;
			dis[i]=0;
			f[i]=1;
			q.push(i);
			while(q.empty()==0){
				int u=q.front();
				bj[u]=0;
				q.pop();
				for(int v=1;v<=n;v++){
					if(abs(a[v]-a[u])>d) continue;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						f[v]=f[u];
						if(bj[v]==0){
							bj[v]=1;
							q.push(v);
						}
					}else if(dis[v]==dis[u]+1){
						f[v]+=f[u];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(f[i]==2) ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
