#include<bits/stdc++.h>
using namespace std;
#define int long long
using p=pair<int,int>;
constexpr int N=2000009;
int a[N];
int vis[N];
int vis2[N];
int sum[N];
int n,d;
int c;
int get(int x){
	queue<int> q;
	q.push(x);
	for(int i=1;i<=n;i++){
		vis[i]=-1;
		sum[i]=0;
	}
	vis[x]=0;
	sum[x]=1;
	while(!q.empty()){
		int st=q.front();
		q.pop();
		int ne=st+1;
		while(a[ne]-a[st]<=d && ne<=n){
			if(vis[ne]==-1){
				vis[ne]=vis[st]+1;
				q.push(ne);
			}
			if(vis[st]+1==vis[ne])
				sum[ne]+=sum[st];
			ne++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(sum[i]==2){
			ans++;
		}
	}
	return ans;
}
void solve(){
	if(0<=c && c<=10){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			ans+=get(i);
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;
	cin>>c>>_;
	while(_--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
