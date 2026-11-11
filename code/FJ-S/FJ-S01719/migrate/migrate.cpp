#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+6;
int n,d,x[N];
int dist[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T;cin>>c>>T;while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int u=1;u<=n;u++){
			cnt[u]=1;
			dist[u]=0;
			for(int v=u+1,l=u;v<=n;v++){
				while(l<v&&x[v]-x[l]>d)l++;
				if(l==v)break;
				dist[v]=dist[l]+1;
				cnt[v]=0;
				for(int i=l;i<v;i++){
					if(dist[i]!=dist[l]||cnt[v]>2)break;
					cnt[v]+=cnt[i];
				}
				if(cnt[v]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
