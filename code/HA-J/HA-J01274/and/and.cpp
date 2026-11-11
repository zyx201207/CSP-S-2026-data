#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],maxx;
void dfs(ll u,ll cnt,ll id){
	if(cnt==m){
		maxx=max(maxx,u);
		return;
	}
	if(id<=n){
		if(u==-1){
			dfs(a[id+1],cnt+1,id+1);
			dfs(-1,cnt,id+1);
		}
		else{
			dfs(u&a[id+1],cnt+1,id+1);
			dfs(u,cnt,id+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(ll i=1;i<=n;i++)maxx=max(a[i],maxx);
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		maxx=a[1];
		for(ll i=2;i<=n;i++)maxx&=a[i];
		cout<<maxx<<endl;
		return 0;
	}
	dfs(-1,0,0);
	cout<<maxx<<endl;
	return 0;
}