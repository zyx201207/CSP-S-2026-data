#include<bits/stdc++.h>
using namespace std;
const int INF=1e8;
int c,n,k;
vector<int> a[2000005];
int ans=INF;
set<int> s;
void init(){
	for(int i=1;i<=n;i++) a[i].clear();
	ans=INF;
	return;
}
bool vis[2000005];
void dfs1(int x,set<int> s1){
	for(int y:a[x]){
		if(s1.count(y)&&!vis[y]){
			vis[y]=true;
			dfs1(y,s1);
		}
	}
}
bool check(set<int> s1){
	int cnt=0;
	for(int x:s1){
		if(!vis[x]){
			cnt++;
			dfs1(x,s1);
		}
	}
	for(int x:s1) vis[x]=false;
	return cnt<=2;
}
int d[2000005];
int make(set<int> s1){
	queue<int> q;
	for(int i=1;i<=n;i++) d[i]=INF;
	for(int x:s1){
		q.push(x);
		d[x]=0;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:a[x]){
			if(d[y]>d[x]+1){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,d[i]);
	}
	//cout<<res<<'\n';
	return res;
}
void dfs(set<int> s1){
	if(s1.size()==k){
		if(check(s1)){
			ans=min(ans,make(s1));
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!s1.count(i)){
			s1.insert(i);
			dfs(s1);
			s1.erase(i);
		}
	}
	return;
}
bool check1(int mid){
	int l=mid+k-2,r=n/2+1-mid;
	if(l>=r) return true;
	if((r-l)/2+1<=mid) return true;
	return false;
}
void subject1(){
	int l=0,r=n/2+1,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check1(mid)){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<res<<'\n';
	return;
}
void solve(){
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(k==n){
		cout<<"0\n";
		return;
	}
	if(c==13||c==14){
		subject1();
		return;
	}
	set<int> se;
	se.clear();
	ans=INF;
	dfs(se);
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
