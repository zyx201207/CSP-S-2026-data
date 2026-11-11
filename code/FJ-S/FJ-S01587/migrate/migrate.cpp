//T3 暴力 5：30开始 6:18结束  40dps 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){
	ll a=0,f=1;
	char c=getchar();
	while (c<'0' or c>'9'){
		if (c=='-')f=-1;
		c=getchar();
	}while (c>='0' and c<='9'){
		a=a*10+c-48;
		c=getchar();
	}return a*f;
}
struct node{
	ll u,step=0;
};
ll c,T,a[N],n,d;
vector<ll>g[N];
ll dis[5500];
int mcount[5005];
bool vis[5050],vis2[5050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	dis[0]=dis[1]=0; 
	while (T--){
		n=read();d=read();
		for (int i=1;i<=n;i++){
			a[i]=read();g[i].clear();
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (a[j]-a[i]>d)break;
				g[i].push_back(j);
			}
		}
		ll ans=0;
		queue<node> q;
		for (int i=1;i<=n;i++){
			q.push({i,0});
			memset(dis,0x3f,sizeof dis);
			memset(vis,0,sizeof vis);
			memset(vis2,0,sizeof vis2);
			memset(mcount,0,sizeof mcount);
			while (q.size()){
				node t=q.front();q.pop();
				for (ll v:g[t.u]){
					if (t.step+1>dis[v])continue;
					q.push({v,t.step+1});
					if (vis[v]==0){
						dis[v]=t.step+1;
						mcount[v]++;
						vis[v]=1;
					}else if (t.step+1==dis[v]){
						mcount[v]++;
						if (mcount[v]==2)ans++;
						else if (mcount[v]>2 and !vis2[v]){
							ans--;vis2[v]=1;
						}
					}
				}
			}while (q.size())q.pop();		
		}
		cout<<ans<<endl;
	}
	return 0;
}

