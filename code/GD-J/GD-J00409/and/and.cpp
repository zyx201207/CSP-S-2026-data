#include<bits/stdc++.h>
using namespace std;
long long n,m,f[200010],vis[200010],l=-1,p=1;
long long ll;
void dfs(int x,long long k,int o){
	if(x>m){
		ll=max(ll,k);
		return;
	}
	for(int i=o;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(x==1) dfs(x+1,f[i],i+1);
			else dfs(x+1,k&f[i],i+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
//	freopen("and.ans","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		l=max(l,f[i]);
		if(f[i]!=f[i-1]&&i!=1) p=1;
		if(i==1)ll=f[1];
		else ll&=f[i];
	}
	if(!p){
		cout<<f[1];
		return 0;
	}
	if(m==1){
		cout<<l;
		return 0;
	}
	if(m==n){
		cout<<ll;
		return 0;
	}
	if(m==2){
		ll=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ll=max(f[i]&f[j],ll);
			}
		}
		cout<<ll;
		return 0;
	}
	ll=0;
	dfs(1,0,0);
	cout<<ll;
	return 0;
}
