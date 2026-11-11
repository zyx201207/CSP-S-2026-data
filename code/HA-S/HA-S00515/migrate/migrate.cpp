#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
int ab(int x){
	return x<0? -x: x;
}
const int N=5005;
int c,t,n,d,ans,a[N],dis[N],cnt[N];
void bfs(int s){
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	for(int i=s+1; i<=n; i++){
		if(ab(a[i]-a[s])<=d){
			dis[i]=1; q.push(i);
		}
	}
	while(!q.empty()){
		int f=q.front(); q.pop();
		for(int i=f+1; i<=n; i++){
			if(ab(a[i]-a[f])<=d){
				if(dis[i]>=dis[f]+1ll){
					if(dis[i]==dis[f]+1ll) cnt[i]++;
					dis[i]=dis[f]+1ll;
					q.push(i);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) if(cnt[i]==1ll) ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=0;
		n=read(),d=read();
		for(int i=1; i<=n; i++) a[i]=read();
		for(int i=1; i<=n; i++) bfs(i);
		printf("%lld\n",ans);
	}
	return 0;
}

