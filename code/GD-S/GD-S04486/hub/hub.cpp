#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n,k,d[N],h[N];
vector<int>v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(d,0,sizeof(d));
		memset(h,0,sizeof(h));
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			d[x]++;d[y]++;
		}
		if(n==k){
			cout<<0;
			continue;
		}
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				h[i]=1;
				q.push(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n-k;i++){
			int x=q.front();
			q.pop();
			ans=max(ans,h[x]);
			for(int y:v[x]){
				if(--d[y]==1){
					h[y]+=h[x];
					q.push(y);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
