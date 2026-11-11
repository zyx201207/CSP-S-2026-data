#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int c,t,n,d;
ll x[N],ans;
int path(int u,int v){
	if(v-u<=d)return 1;
	int res=1;
	for(int i=u;i<v;i++){
		if(x[i+1]-x[i]>d)return n;
	}
	for(int l=u,r=u+1;r<=v;r++){
		if(r-l>d)res++,l=r;
	}
	return res;
}
void dfs(int u,int v,int l,int lim,int &cnt){
	if(u<v&&l>=lim)return;
	if(u==v){
		cnt++;
		return;
	}
	for(int i=upper_bound(x+1,x+1+n,x[u]+d)-x-1;i>u;i--){
		dfs(i,v,l+1,lim,cnt);
		if(cnt>2)return;
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		int m=path(i,j);
		if(m==n)continue;
		int cnt=0;
		dfs(i,j,0,m,cnt);
		if(cnt==2)ans++; 
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	for(cin>>c>>t;t--;)solve(); 
	return 0;
}

