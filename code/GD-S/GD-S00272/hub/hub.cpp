#include<bits/stdc++.h>
using namespace std;
vector<int> M[15];
bool flag[15];
int n,k,sum;
int ans=INT_MAX;
int t[15];
int find(int node){
	if(t[node]==node) return node;
	return t[node]=find(t[node]);
}
int d[15];
queue<int> q;
void check(){
	iota(t+1,t+n+1,1);
	fill(d+1,d+n+1,INT_MAX);
	int cnt=k;
	for(int i=1;i<=n;i++){
		for(int j:M[i]){
			if(find(i)!=find(j)&&flag[i]&&flag[j]){
				t[find(i)]=find(j);
				cnt--;
			}
		}
	}
	if(cnt>2) return;
	for(int i=1;i<=n;i++){
		if(flag[i]){
			d[i]=0;
			q.push(i);
		} 
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(int i:M[top]){
			if(d[i]>d[top]+1){
				d[i]=d[top]+1;
				q.push(i);
			}
		}
	}
	int maxx=-1;
	for(int i=1;i<=n;i++) maxx=max(maxx,d[i]);
	ans=min(ans,maxx);
}
void dfs(int t){
	if(t>n){
		if(sum==k) check();
		return;
	}
	dfs(t+1);
	if(sum+1<=k){
		sum++;
		flag[t]=1;
		dfs(t+1);
		sum--;
		flag[t]=0;
	}
}
void solve(){
	ans=INT_MAX;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int tmp,tmp2;
		cin>>tmp>>tmp2;
		M[tmp].push_back(tmp2);
		M[tmp2].push_back(tmp);
	}
	dfs(1);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) M[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
