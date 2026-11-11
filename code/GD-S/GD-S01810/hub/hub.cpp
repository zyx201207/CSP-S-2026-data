#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,n,k,ans;
int b[1000005];
vector<int> a[1000005];
vector<int> v;
void dfs(int x,int y){
	if(y>=k){
		int maxx=0,cnt=0;
		for(int i=1;i<=n;i++)b[i]=1;
		for(auto i:v){
			b[i]=0;
		}
		queue<int> q;
		for(auto i:v){
			if(!b[i]){
				cnt++;
				q.push(i);
				while(q.size()){
					int u=q.front();
					q.pop();
					for(auto i:a[u]){
						if(!b[i]){
							b[i]=1;
							q.push(i);
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)b[i]=0;
		for(auto i:v){
			b[i]=1;
			q.push(i);
		}
		if(cnt>2)return;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto i:a[u]){
				if(!b[i]){
					b[i]=b[u]+1;
					maxx=max(maxx,b[i]-1);
					q.push(i);
				}
			}
		}
		ans=min(ans,maxx);
		return;
	}
	if(x>n){
		return;
	}
	v.push_back(x);
	dfs(x+1,y+1);
	v.pop_back();
	dfs(x+1,y);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=LONG_LONG_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
