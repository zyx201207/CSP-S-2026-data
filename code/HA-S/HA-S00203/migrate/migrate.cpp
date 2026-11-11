#include<bits/stdc++.h>
#define int long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int c,t,n,d,cnt[2000005],dis[2000005];
bool vis[2000005];
vector<int>x;
signed main(){
	fre("migrate");
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		x.resize(n);
		for(int&i:x)cin>>i;
		int ans=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				dis[j]=4611686018427387903;
				vis[j]=0;
				cnt[j]=0;
			}
			queue<int>q;
			dis[i]=0;
			cnt[i]=1;
			q.push(i);
			while(q.size()){
				int u=q.front();
				q.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(int j=u+1;j<n&&x[j]-x[u]<=d;j++){
					int w=dis[u]+1;
					if(dis[j]>w){
						dis[j]=w;
						q.push(j);
						cnt[j]=cnt[u];
					}
					else if(dis[j]==w)cnt[j]+=cnt[u];
				}
			}
			for(int j=i+1;j<n;j++)if(cnt[j]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

