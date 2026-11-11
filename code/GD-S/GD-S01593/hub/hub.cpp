#include<bits/stdc++.h>
using namespace std;
const int N=1000007;
int u,t,n,m,x,y,ct,f[N],g[N],d[N],ans,mx;
vector<int>v[N];
queue<int>q;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&u,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=n;
		for(int i=1;i<(1<<n);i++){
			//cout<<i<<' '<<__builtin_popcount(i)<<endl;
			if(__builtin_popcount(i)>m) continue;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					f[j]=1;
					d[j]=0;
					q.push(j);
				}
				else{
					f[j]=0;
					d[j]=998244353;
				}
				g[j]=0;
			}
			while(!q.empty()){
				x=q.front();
				q.pop();
				for(int i=0;i<v[x].size();i++){
					y=v[x][i];
					if(d[y]>d[x]+1){
						d[y]=d[x]+1;
						q.push(y);
					}
				}
			}
			mx=0;
			for(int j=1;j<=n;j++){
				//cout<<d[j]<<' ';
				mx=max(mx,d[j]);
			}
			//cout<<endl;
			ct=0;
			for(int j=1;j<=n;j++){
				if(f[j]&&!g[j]){
					ct++;
					q.push(j);
					while(!q.empty()){
						x=q.front();
						q.pop();
						for(int i=0;i<v[x].size();i++){
							y=v[x][i];
							if(f[y]&&!g[y]){
								g[y]=1;
								q.push(y);
							}
						}
					}
				}
			}
			if(ct<=2) ans=min(ans,mx);
		}
		cout<<ans<<endl;
	}
	return 0;
}
