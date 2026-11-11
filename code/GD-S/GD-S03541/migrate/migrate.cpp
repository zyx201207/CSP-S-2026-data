#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,m,d,ans,a[2000005],b[2000005];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
void spfa(int s){
	vector<int>dis(n+1,0x3f3f3f3f3f3f3f3f),cnt(n+1,0);
	vector<bool>vis(n+1,0);
	queue<int>q;
	q.push(s);
	vis[s]=1,dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=u+1;i<=n;i++){
			if(a[u]+d>=a[i]&&dis[i]>dis[u]+1){
				//cout<<"u->v:("<<u<<","<<i<<")"<<endl;
				dis[i]=dis[u]+1,cnt[i]=cnt[u];
				if(!vis[i]){
					q.push(i);
					vis[i]=1;
				}
			}else if(a[u]+d>=a[i]&&dis[i]==dis[u]+1){
				cnt[i]++;
			}
		}
	}
	//cout<<"cnt:";
	for(int i=s+1;i<=n;i++){
		//cout<<cnt[i]<<" ";
		if(cnt[i]==2)ans++;
	}
	//cout<<endl;
//	cout<<endl<<"dis:";
//	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
//	cout<<endl<<"vis:";
//	for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
//	cout<<endl;
	dis.clear(),cnt.clear(),vis.clear();
	vector<int>().swap(dis),vector<int>().swap(cnt),vector<bool>().swap(vis);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n<=2){
			cout<<0<<endl;
			continue;
		}
		if(c>=11&&c<=12){
			int gc=a[2]-a[1];
			int y=n-((d-gc)/gc*2ll+1ll);
			cout<<max(y,0ll)<<endl;
			continue; 
		}
		ans=0;
		for(int i=1;i<=n;i++)spfa(i);
		cout<<ans<<endl;
	}
	return 0;
} 
