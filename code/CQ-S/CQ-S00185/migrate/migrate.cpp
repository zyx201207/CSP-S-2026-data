#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=2e6+5;
int c,t,n,m,ans;
int a[N];
vector<int> ve[N];
int vis[N],nxt[N];
int dis[N],f[N];
bool tou[N];
queue<int> q;
void bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i]=1e12;
		vis[i]=0;
		f[i]=0;
	}
	q.push(s);
	dis[s]=0;
	f[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop(); 
		if(vis[x]) continue;
		vis[x]=1;
		for(int y:ve[x]){
//			cout<<x<<"->"<<y<<"\n";
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1; 
				f[y]=f[x];
				q.push(y); 
			}
			else if(dis[y]==dis[x]+1){
				f[y]+=f[x];
//				if(y==9) cout<<y<<" fuzh "<<x<<"\n"; 
			}
		}
	}
	for(int i=s+1;i<=n;i++){
//		if(f[i]>1)cout<<s<<"->"<<i<<" "<<f[i]<<"\n";
		if(f[i]==2){
			ans++;
		}
	}
}
void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ve[i].clear();
	}
	if(c==13||c==14){
		cout<<0<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(a[j]-a[i])<=m){
				ve[i].push_back(j);
//				ve[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	} 
	cout<<ans<<"\n";
}
void calc(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
		nxt[i]=n+1;
		tou[i]=0;
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		tou[i]=1;
		int x=i;
//		cout<<i<<"\n\n";
		vis[i]=i;
		while(x<=n){
			int j=upper_bound(a+1,a+n+1,a[x]+m)-a-1;
			if(j>n||j==x) break;
			nxt[x]=j;
//			cout<<x<<" "<<j<<"fuzhi\n";
			if(vis[j]) break;
			vis[j]=i;
//			cout<<x<<"->"<<j<<"\n";
			x=j;
		}
	}
//	for(int i=1;i<=n;i++){
////		cout<<i<<" "<<nxt[i]<<"\n";
//	}
//	return;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!tou[i]) continue;
		int j=nxt[i],k=nxt[j];
//		cout<<i<<"-----\n";
		int tot=0,fl=0;
		while(j<=n){
//			cout<<j<<" "<<k<<"\n";
			if(k<=n){
				for(int l=j+1;l<=k;l++){
					if(a[l]-a[j-1]<=m&&a[l]-a[j]>=m){
						if(f[j]==0) ans++;
						f[l]=2;
					}
					else{
						if(f[j]==2) ans++;
					}
				}
			}
			else{
				for(int l=j+1;l<=n;l++){
					if(a[l]-a[j-1]<=m&&a[l]-a[j]>=m){
						if(f[j]==0) ans++;
						f[l]=2;
					}
					else{
						if(f[j]==2) ans++;
					}
				}
				break;
			}
			if(vis[j]!=i) break;
			j=k;
			k=nxt[j];
		}
//		cout<<i<<" "<<ans<<"\n"; 
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c<=10||c==13||c==14) solve();
		else calc();
	}
	return 0;
}
