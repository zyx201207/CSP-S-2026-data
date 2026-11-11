#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int a[5005];
int dis[5005],cnt[5005];//最短路计数 
vector<int>vc[5005];//建图
queue<int>q;
void bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
	}
	for(int i=1;i<=n;i++){
		cnt[i]=0;
//		cout<<cnt[i]<<" ";
	}
//	cout<<"\n";
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<u<<" "<<cnt[u]<<"\n";
		for(auto v:vc[u]){
			if(dis[u]+1<dis[v]){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push(v);
			}else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
	while(!q.empty()){
		q.pop();
	}
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
//		int l=0;//第一个>=a[i]-d的位置
//		a[0]=-1e18-1; 
//		a[n+1]=1e18+1;
////		cout<<"p:"; 
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//		}
//		for(int i=1;i<=n;i++){
//			while(a[l]<a[i]-d){//说明那个点可以跳到这个点 
//				l++;
//			}
////			cout<<a[l]+d<<" "<<a[i+1]<<"\n";
//			if(i<=l||a[l]+d>=a[i+1]){//条件1说明这个点根本到不了任何地方,条件2说明这个点不是那个点的极限 
//				continue;
//			}
//			int cnt=0,r=l;
//			while(r<i&&a[r]+d<a[i+1]){
//				cnt++;
//				r++;
//			}
//			p[i]=p[l]+cnt;
//			dd[i]=p[l];//多跳一位 
////			cout<<p[i]<<" ";
//		}
////		cout<<"\n";
//		l=0;
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			while(a[l]<a[i]-d){
//				l++;
//			}
//			if(i<=l+1||a[l]+d>=a[i+1]){
//				continue;
//			}
//			dp[i]=1+dp[l]+dd[l+1];
//			ans+=dp[i];
//		}
//		for(int i=1;i<=n;i++){
//			dd[i]=p[i]=dp[i]=0;
//		}
//		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					vc[i].push_back(j);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int i=1;i<=n;i++){
//				cout<<cnt[i]<<" ";
				if(cnt[i]==2){
					ans++;
				}
			}
//			cout<<"\n";
		}
		for(int i=1;i<=n;i++){
			vc[i].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
