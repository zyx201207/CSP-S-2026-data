#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=5005;
int c,t,n,q[N],hh,tt,dist[N],cnt[N];long long d,x[N];
void bfs(int rt){
	for(int i=1;i<=n;i++)dist[i]=n,cnt[i]=0;
	dist[rt]=0;cnt[rt]=hh=1;tt=0;
	q[++tt]=rt;
	while(hh<=tt){
		int u=q[hh];
		hh++;
		for(int v=u+1;v<=n;v++){
			if(x[v]-x[u]>d)break;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				cnt[v]=cnt[u];
				q[++tt]=v;
			}
			else if(dist[v]==dist[u]+1)cnt[v]+=cnt[u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=1;j<=n;j++){
					if(cnt[j]==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			tt=0;long long ans=0;
			for(int i=2;i<=n-2;i++){
				if(x[i+2]-x[i]<=d&&x[i+1]-x[i-1]<=d&&x[i+2]-x[i-1]>d)q[++tt]=i;
			}
			q[tt+1]=0;
			for(int i=1;i<=tt;i++){
				int u=q[i],l=1,r=1;
				for(int j=u-2;j>=1;j--){
					if(j+1==q[i-1]||x[j+1]-x[j]>d)break;
					l++;
				}
				for(int j=u+3;j<=n;j++){
					if(j-2==q[i+1]||x[j]-x[j-1]>d)break;
					r++;
				}
				ans+=1ll*l*r;
			}
			cout<<ans<<'\n';	
		}
	}
	return 0;
}