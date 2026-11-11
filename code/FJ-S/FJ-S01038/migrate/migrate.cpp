#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=1e4+5,inf=0x3f3f3f3f;
int c,t,cnt[N],mi[N];
bool vis[M][M];
queue<pair<int,int> > q;
long long d,n,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		if(d==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			cout<<(2*d-1)*(n-d)<<endl;
			continue;
		}
		else if(c<=10){
			for(int i=1;i<n;i++){
				while(!q.empty()) q.pop();
				memset(cnt,0,sizeof(cnt));
				q.push(make_pair(i,0));
				memset(vis,0,sizeof vis);
				memset(mi,inf,sizeof mi);
				cnt[i]=1;
				while(!q.empty()){
					int u=q.front().first,t=q.front().second;
					q.pop();
					mi[u]=min(mi[u],t);
					int v=u+1;
					t++;
					while(x[u]+d>=x[v]&&v<=n){
						if(cnt[v]==0) cnt[v]=1;
						else if(cnt[v]==1&&vis[v][t]&&t<=mi[v]) cnt[v]=2,ans++;
						else if(cnt[v]==2&&vis[v][t]&&t<=mi[v]) cnt[v]=-1,ans--;
						vis[v][t]=1;
						q.push(make_pair(v,t+1));
						v++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}