#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=1e3+10;
int n,d,a[N],dis[M][M],cnt[M][M];
vector<int> vc;
void check(){
	if(vc.empty()) return;
	int sz=vc.size();
	if(sz==1) return;
	for(int i=1;i<sz;i++)
		if(a[vc[i]]-a[vc[i-1]]>d) return;
	if(sz-1==dis[vc[0]][vc[sz-1]]) cnt[vc[0]][vc[sz-1]]++;
}
void dfs(int u){
	if(u==n+1){check();return;}
	vc.push_back(u);
	dfs(u+1);
	vc.pop_back();
	dfs(u+1);
}
void work1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(abs(a[i]-a[j])<=d) dis[i][j]=1;
			else dis[i][j]=1e9;
			cnt[i][j]=0;
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(cnt[i][j]==2) ans++;
	cout<<ans<<endl;
}
void work2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(d<a[2]-a[1]){cout<<0<<endl;return;}
	int mx=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]>d) break;
		mx=i;
	}
	int len=mx+mx-2;
	if(len<4) cout<<0<<endl;
	else cout<<max(0ll,n-len+1)<<endl;
}
void work3(){
}
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c<=10) work1();
		else work2();
	}
}
