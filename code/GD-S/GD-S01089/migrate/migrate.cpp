#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int c,T,dis[N+10],sum[N+10];
LL a[N+10];
vector<int> adj[N+10];
queue<pair<int,int>>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		int n;
		LL d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			adj[i].clear();
		}
		a[n+1]=INF;
		for(int i=1;i<=n;i++){
			int b=upper_bound(a,a+n+2,a[i]+d)-a;
			//cout<<"b"<<b<<endl;
			for(int j=i+1;j<b;j++)adj[i].push_back(j);
		}
		for(int i=1;i<=n;i++){
			memset(sum,0,sizeof(sum));
			q.push({i,0});
			while(!q.empty()){
				pair<int,int> p=q.front();
				q.pop();
				if(sum[p.first]==0){
					sum[p.first]=1;
					dis[p.first]=p.second;
				}else if(p.second<dis[p.first]){
					sum[p.first]=1;
					dis[p.first]=p.second;
				}else if(p.second==dis[p.first]){
					sum[p.first]++;
				}
				for(int v:adj[p.first]){
					q.push({v,p.second+1});
				}
			}
			for(int j=i+1;j<=n;j++){
				if(sum[j]==2){
					//cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
