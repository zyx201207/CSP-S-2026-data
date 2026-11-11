#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
#define fi first
#define se second
const int N=2000010;
int c,T;
int n,d,ans=0;
int a[N];
vector<int>vec[N];
int dis[N],vis[N],num[N];
priority_queue<PII,vector<PII>,greater<PII> >q;
void dij(int st){
	for(int i=1;i<=n;i++)dis[i]=1e18,num[i]=0,vis[i]=0;
	q.push({dis[st]=0,st});
	num[st]=1;
	while(!q.empty()){
		auto t=q.top().se;q.pop();
//		cout<<t<<"\n";
		if(vis[t])continue;
		vis[t]=1;
		for(auto v:vec[t]){
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1,num[v]=num[t];
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[t]+1)num[v]+=num[t];
		}
	}
//	cout<<st<<":\n";
	for(int i=st;i<=n;i++){
//		cout<<num[i]<<" ";
		if(num[i]==2)ans++; 
	}
//	cout<<"\n";
} 
void work(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],vec[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(abs(a[i]-a[j])<=d)vec[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)work();
	return 0;
} 
