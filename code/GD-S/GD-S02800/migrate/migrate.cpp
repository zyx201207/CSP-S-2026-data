#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int N=2e6+5;
ll t,n,d,a[N],f[N],dis[N];
vector<int>e[N];
queue<int>q;
bool bfs(int st,int ed){
//	if(st%10==0) cout<<rand()<<endl;
//	cout<<endl<<"st="<<st<<",ed="<<ed<<endl;
	memset(f,0,sizeof(f));
	memset(dis,INF,sizeof(dis));
	while(!q.empty())
		q.pop();
	q.push(st);
	f[st]=1;
	dis[st]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		cout<<"u="<<u<<endl;
		for(auto v:e[u]){
			if(v>ed) break;
			if(dis[u]+1<=dis[v]){
//				cout<<"v="<<v<<",";
				if(dis[u]+1<dis[v]){
					q.push(v);
					dis[v]=dis[u]+1;
				}
				f[v]+=f[u];
			}
		}
//		cout<<endl;
	}
//	for(int i=st;i<=ed;i++)
//		printf("f[%d]=%lld,dis[%d]=%lld\n",i,f[i],i,dis[i]);
	return f[ed]==2;
}
int main(){
//	system("fc migrate3.out migrate3.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)	
			e[i].clear();
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d) break;
//				cout<<i<<" to "<<j<<endl;
				e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(bfs(i,j)) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
