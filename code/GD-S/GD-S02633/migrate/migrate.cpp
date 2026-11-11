#include <bits/stdc++.h>

#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define endl "\n"

using namespace std;

const int inf=1e7;

const int N=2000000;

int c,t;

int n,d;
struct node{int s,b;}a[N+5];

vector<int>q[N+5];

queue<pr>p;
int vis[N+5]; 
int sum[N+5];


void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) q[i].clear();
	for(int i=1;i<=n;i++){
		a[i].b=i;
		cin>>a[i].s;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i].s-a[j].s)<=d) {q[a[i].b].pb(a[j].b);q[a[j].b].pb(a[i].b);} 
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		while(!p.empty()) p.pop();
		for(int j=1;j<=n;j++) {vis[j]=inf;sum[j]=0;}
		p.push(mp(i,0));
		while(!p.empty()){
			pr mq=p.front();
			p.pop();
			if(c==13||c==14) if(mq.second>2) continue;
			if(vis[mq.first]<mq.second) continue;
			if(vis[mq.first]==mq.second) {sum[mq.first]++;}
			else {vis[mq.first]=mq.second;sum[mq.first]=1;}
			
			for(int ne:q[mq.first]){
				if(vis[ne]>=mq.second+1) p.push(mp(ne,mq.second+1));
			}
		}
		for(int j=1;j<=n;j++) ans+=(sum[j]==2);
	}
	cout<<ans/2<<endl; 
}

signed main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
//32pts~48pts 
