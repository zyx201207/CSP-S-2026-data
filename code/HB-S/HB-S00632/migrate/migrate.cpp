#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
vector<int> mp[100005];
int a[100005];
int ds[100005];
int pth[100005];
queue<int> q;
void dfs(int nw,int f){
	for(auto v:mp[nw]){
		if(v==f)continue;
		if(ds[v]==ds[nw]+1){
			pth[v]++;
			dfs(v,nw);
		}
	}
}
int bfs(int st){
	q.push(st);
	ds[st]=1e18;
	while(!q.empty()){
		int nw=q.front();
		q.pop();
		for(auto v:mp[nw]){
			if(ds[v]==0){
				ds[v]=ds[nw]+1;
				q.push(v);
			}
		}
	}
	dfs(st,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(pth[i]==2){
			//cout<<st<<' '<<i<<endl;
			cnt++;
		}
		pth[i]=0;
		ds[i]=0;
	}
	return cnt;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					mp[i].push_back(j);
					mp[j].push_back(i);
				}
				else{
					break;
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		for(int i=1;i<=n;i++)mp[i].clear();
		cout<<ans/2<<endl;
	}

	return 0;
}
