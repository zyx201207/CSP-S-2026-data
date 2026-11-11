#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[5001];
int ans;
void bfs(int s,int e){
	queue<int> q;
	vector<int> vis(5001);
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int cur=q.front();
		if(cur==e){
			int num=1;
			q.pop();
			while(!q.empty()){
				int te=q.front();
				q.pop();
				if(te==e) num++;
			}
			if(num==2) ans++;
			return;
		}
		q.pop();
		for(auto it:g[cur]){
			if(!vis[it]) q.push(it);
			vis[it]=1;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	
	while(t--){
		ans=0;
		int n,d;cin>>n>>d;
		vector<int>a(n+1);
		int f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2) f=0;
		}
		if(f){
			int temp=d/(a[2]-a[1]);
			if(temp<2)cout<<'0'<<endl;
			else cout<<max(0LL,n-temp-(temp-1))<<endl;
			continue;
		}
		for(int i=n;i>=1;i--){
			int j=i;
			while(1){
				if((a[i]-a[j])>d) break;
				g[i].push_back(j);
				g[j].push_back(i);
				j--;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				bfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
