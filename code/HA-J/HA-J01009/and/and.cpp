#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll maxx=0;
bool vis[200005];
void dfs(ll x,ll mm,ll sum){
	if(mm==m){
		maxx=max(sum,maxx);
		return ;
	}
	if(x>n){
		return ;
	}
	vis[x]=1;
	for(int i=x+1;i<=n;i++){
		if(vis[i]!=1){
			dfs(i,mm++,(sum&a[i]));
		}
	}
	vis[x]=0;
	dfs(x+1,0,a[x+1]);
}
bool cmp(ll x,ll y){
	return (x>y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}else{
		dfs(1,0,a[1]);
		cout<<maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

