#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,_,h[2000005],f[2000005][28],vis[2000005],d[2000005],root,n,k;
vector<ll>v[20000005];
void dfs(ll x,ll fa){
	h[x]=h[fa]+1;
f[x][0]=fa;
	for(auto ed:v[x]){
		dfs(ed,x);
	}
}void build(){
	for(int i=1;i<=27;i++){
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
}
ll lca(ll a,ll b){

	if(h[a]>h[b]){
		swap(a,b);
	}ll need=h[b]-h[a];
	while(need){
		a=f[a][(need&-need)];
		need-=(need&-need);
	}
	while(a!=b){
		a=f[a][0],b=f[b][0];
		if(vis[a]||vis[b])return 2000001;
	}
	return a;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--){
	memset(vis,0,sizeof(vis));
	memset(h,0,sizeof(h));
	cin>>n>>k;
	if((n-1-2*k)/2>0){
		cout<<(n-1-2*k)/2;
	}else if((n-1-2*k)/2==0){
		cout<<1;
	}else if((n-1-2*k)/2<0){
		if(n==k){
			cout<<0;
		}else if(n/2==k){
			cout<<1;
		}else cout<<2;
	}cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
