#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e4+10;
int c,t;
ll n,d;
ll a[N];
ll cnt[N];
ll tim[N];
queue<ll> q;
ll ppp;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ppp=0;
		cin>>n>>d;
		vector<ll> g[n+10];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(max(a[i],a[j])-min(a[i],a[j])<=d && i!=j){
					g[i].push_back(j);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(auto v:g[i]) cout<<v<<' ';
//			cout<<'\n';
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(tim,0,sizeof(tim));
				memset(cnt,0,sizeof(cnt));
				q.push(i);
				
				cnt[i]=1;
				for(int i=1;i<=n;i++) tim[i]=INT_MAX;
				tim[i]=1;
				int ans=INT_MAX; 
				while(!q.empty()){
					ll p=q.front();
					q.pop();
					if(tim[p]>=ans) continue;
					for(auto v:g[p]){
						if(tim[p]+1>tim[v]) continue;
						cnt[v]+=cnt[p];
						tim[v]=tim[p]+1;
						if(v==j && ans==INT_MAX) ans=tim[v]; 
						if(cnt[p]==1) q.push(v); 
					}
				}
//				for(int k=1;k<=n;k++) cout<<cnt[k]<<' ';
//				cout<<"\n";
//				for(int k=1;k<=n;k++) cout<<tim[k]<<' ';
//				cout<<"\n";
				if(cnt[j]==2){
					ppp++; 
				} 
			}
		}
		cout<<ppp<<'\n';
	} 
	return 0;
}

