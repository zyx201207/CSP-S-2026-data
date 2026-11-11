#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,d,a[N],cnt[N],dis[N];
vector<int> e[N];
bool vis[N];
struct node{
	int u,w;
	bool friend operator<(node A,node B){
		return A.w>B.w;
	}
};
void Di(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<(int)e[u].size();i++){
			int v=e[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
				q.push({v,dis[v]});
			}
		} 
	} 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	if(11<=c&&c<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int x=a[2]-a[1];
			int k=d/x;
			if(k==1){
				cout<<0<<endl;
			}else{
				int q=n/k;
				if(n%k==0)q--;
				cout<<q<<endl;
			}
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			e[i].clear();
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		for(int i=1;i<=n;i++){
			int tot=i+1;
			while(tot<=n&&a[tot]-a[i]<=d){
				e[i].push_back(tot);
				//cout<<i<<" "<<tot<<endl;
				tot++;
			}			
		}		
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			cnt[i]=1;
			Di(i);
			for(int j=i+1;j<=n;j++){
				//cout<<cnt[j]<<" ";
				if(cnt[j]==2)ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/
