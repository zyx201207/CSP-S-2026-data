#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll tim;
int w[500005];
pair<int,int> qs[100005];
set<int> a[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(12<=c&&c<=19){
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			ll b,t;cin>>b>>t;
			tim=t;
			a[i].insert(b);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i].first>>qs[i].second;
		bool vis[100005];
		queue<pair<int,int>> que;
		que.push({qs[i].first,1});
		//int cnt=0;
		int ans=0;
		vis[que.front().first]=1;
		while(!que.empty()){
			
			int u=que.front().first;
			//vis[u]=1;
			int cnt=que.front().second;
			//cout<<cnt<<endl;
			if(u==qs[i].second){
				ans=w[qs[i].first]+w[qs[i].second]+tim*2*(cnt-1);
				break;
			}			
			que.pop();
			for(int j=1;j<=n;j++){
				if(a[j].count(u)){
					for(auto k:a[j]){
						if(k!=u&&vis[k]==0){
							que.push({k,cnt+1});
							vis[k]=1;						
						}
						//cout<<1<<endl;
					}
				}
				//cout<<2<<endl;
			}
		}
		cout<<ans<<endl;
	}
	
	
	}
}
