#include<bits/stdc++.h>
#define Y(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
typedef long long ll;
using namespace std;
ll n,m,a[200005],s[200005],ans;
bool vis[200005];
inline void dfs(ll u,ll v,ll x){
	if(u==m){
		if(v>ans)ans=v;
		return ;
	}
	for(int i=x;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(u+1,v&a[i],i+1);
			vis[i]=0;
		}
	}
}
inline ll r(){
	ll x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	Y("and");
	n=r(),m=r();
	for(int i=1;i<=n;i++)a[i]=r(),s[i]=s[i-1]&a[i];
	if(n==m){
		cout<<s[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i],2);
		vis[i]=0;
	}
	cout<<ans;
}
//Trick||Treat!
