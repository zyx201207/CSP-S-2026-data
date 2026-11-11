#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t;
int n,k;
int d[N],h[N],vis[N];
vector<int> a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)d[i]=0,a[i].clear(),h[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			d[u]++;
			d[v]++;
		}
		if(n==k){
			cout<<0;
			continue;
		}
//		for(int i=1;i<=n;i++)vis[i]=0;
		queue<int> q;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(d[i]==1){
//				cout<<i<<" ";
				q.push(i);
				h[i]=1;
			}
		}
//		cout<<endl;
		for(int i=1;i<=n-k-ans&&!q.empty();i++){
			int t=q.front();
			q.pop();
//			cout<<n-k-ans<<" "<<ans<<endl;
			ans=max(ans,h[t]);
			for(int j:a[t]){
				if(--d[j]==1){
//					cout<<j<<endl;
					vis[i]=1;
					h[j]=h[t]+1;
					q.push(j);
				}
			}
		}
		cout<<ans<<endl;
	}
}
