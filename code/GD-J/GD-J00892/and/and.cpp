#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m,ans=0,a[maxn];
void dfs(int id,int m,int t){
	if(m==0){
		ans=max(ans,t);
		return;
	} 
	for(int i=id;i<=n;i++){
		dfs(i+1,m-1,t&a[i]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m,(1<<30)-1);
	cout<<ans<<"\n";
	return 0;
} 
