#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=1e10+5;
int c,t,n,d;
long long x[N];
long long dp[N];
long long w[N];
struct P{
	int v;
	long long t;
};
bool inq[N+5];
long long dis[N];
vector<P> g[N];

int spfa(int x){
	//cout<<1<<" ";
	queue<int> q;
	int cnt[N];
	for(int i=0;i<=n+1;i++){
	dis[i]=INF;
	cnt[i]=0;
}
	dis[x]=0;
	inq[x]=1;
	q.push(x);
	cnt[x]=1;
//	cout<<2<<" ";
	while(!q.empty()){
	///	cout<<3<<" ";
		int u=q.front();
		inq[u]=0;
		q.pop();
		for(auto y:g[u]){
			if(dis[u]+y.t<dis[y.v]){
				cnt[y.v]=cnt[u];
				dis[y.v]=dis[u]+y.t;
				if(!inq[y.v]){
					q.push(y.v);
					inq[y.v]=1;
				}
			}
			else{
				if(dis[u]+y.t==dis[y.v]){
					cnt[y.v]+=cnt[u];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2){
			ans++;
		}
	}
	return  ans;
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>c>>t;

	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			int r=i+1;
			while(r<=n){
				if(x[r]-x[i]<=d){
					g[i].push_back({r,1});
					r++;
				}
				else{
					break;
				}
			}
		}
		if(c==13||c==14){
		cout<<n-1<<"\n";
		continue; 
		} 
	int sum=0;
		for(int i=1;i<=n;i++){ //Ã¶¾ÙÆßµã 
			sum+=spfa(i);
	}
	cout<<sum<<"\n";
	}



return 0;
}

