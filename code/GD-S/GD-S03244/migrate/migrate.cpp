#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
const int inf=2e18;
int n,d;
int x[N];
int cnt[N],sh[N];
void bfs(int s){
	int ans=0;
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		auto t=q.front();
		q.pop();
		if(sh[t.first]==t.second) cnt[t.first]++;
		else if(sh[t.first]>t.second){
			sh[t.first]=t.second;
			cnt[t.first]=1;
		}else continue;
		for(int i=t.first+1;i<=n;i++){
			if(x[i]-x[t.first]>d) break;
			q.push({i,t.second+1});
		} 
	} 
}
void solve(){
	int ans=0;
	cin>>n>>d;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=2;i<n;i++){
		if(x[i]-x[i-1]!=x[i+1]-x[i]){f=0;break;}
	}
	if(f){
		int ans=0;
		if(d==1){
			cout<<0<<endl;
		}
		for(int i=3;i<=n;i++){
			if((i-1)*(x[2]-x[1])%d==d-1) ans+=n-i+1;
		}
		cout<<ans<<endl;
		return;
	}
	for(int s=1;s<n-2;s++){
		for(int i=1;i<=n;i++) sh[i]=inf,cnt[i]=0;
		bfs(s);
		for(int i=1;i<=n;i++){
			if(cnt[i]==2) ans++;
		}
	} 
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);	
	int _,__;
	cin>>__>>_;
	while(_--) solve();
}
