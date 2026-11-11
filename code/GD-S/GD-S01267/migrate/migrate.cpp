#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+5;
int n,d,x[MAXN],ans[MAXN],dis[MAXN];
vector<int> g[MAXN];
void dij(int s){
	for(int i=1;i<=n;i++) dis[i]=2e9,ans[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,s));
	ans[s]=1;dis[s]=0;
	while(!q.empty()){
		int t=q.top().second;q.pop();
//		cout<<t<<":";
		for(auto i:g[t]){
//			cout<<i<<':'<<dis[i]<<' ';
			if(dis[t]+1<dis[i]){
				dis[i]=dis[t]+1;ans[i]=ans[t];
				q.push(make_pair(dis[i],i));
			}
			else if(dis[t]+1==dis[i]) ans[i]++;
		}
//		cout<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) g[i].push_back(j);//,cout<<i<<' '<<j<<endl;
				else break;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			dij(i);
//			cout<<i<<":"<<endl;
			for(int j=1;j<=n;j++) cnt+=(ans[j]==2);//,cout<<ans[j]<<' ';
//			cout<<endl;
		}
		cout<<cnt<<endl;
	} 
	return 0;
}
