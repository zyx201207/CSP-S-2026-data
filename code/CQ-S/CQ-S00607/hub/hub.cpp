#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pair;
const int N=1e6+5;
int n,k;
vector<int> v[N];
bool f[N],flg[N];
int dis[N];
int ans;
int q[N],l,r;
void bfs1(int u){
	l=1;
	r=0;
	q[++r]=u;
	while(l<=r){
		int o=q[l];
		l++;
		for(int i:v[o]){
			if(f[i]==1&&flg[i]==0){
				flg[i]=1;
				q[++r]=i; 
			}
		}
	}
}
void bfs(int u){
	l=1;
	r=0;
	q[++r]=u;
	while(l<=r){
		int o=q[l];
	//	cout<<o<<"  "<<dis[o]<<endl;
		l++;
		for(int i:v[o]){
			if(dis[i]>dis[o]+1){
				dis[i]=dis[o]+1;
				q[++r]=i; 
			}
		}
	}
}
void dfs(int u,int sum){
	if(n-u+1+sum<k) return;
	if(sum>k) return;
	if(u>n){
		int c=0;
		for(int i=1;i<=n;i++){
			dis[i]=1e9;
		//	cout<<f[i];
			if(f[i]==1&&flg[i]==0){
				bfs1(i);
				c++;
			}
			if(f[i]==1) dis[i]=0;
		}
	//	cout<<"\n"<<c<<"\n";
		for(int i=1;i<=n;i++) flg[i]=0;
		if(c>2) return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(f[i]) bfs(i);
		}
		for(int i=1;i<=n;i++){
			res=max(res,dis[i]);
	//		cout<<dis[i]<<" ";
		}
	//	cout<<"\n";
		ans=min(ans,res);
		return;
	}
	dfs(u+1,sum);
	f[u]=1;
	dfs(u+1,sum+1);
	f[u]=0;
}
void mian(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=1e9;
	dfs(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++) v[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	if(13<=c&&c<=14){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
			}
			if(k==n) cout<<"0\n"; 
			else cout<<((n/2+2)-k+3)/4<<"\n";
		}
		exit(0);
	}
	while(t--){
		mian();
	}
	return 0;
}
/*
Missing Halloween

Byebye
*/
