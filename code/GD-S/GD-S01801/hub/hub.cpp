#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10,M = 5e2+10;
long long a[N],dp[N],qzh[N];
int mxr[N],mnl[N],pre[N],nxt[N],len[N],sz[N];
bool vis[N];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
	}
	if(k>=n-2){
		cout<<1<<'\n';
	}else{
		cout<<2<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	} 
	return 0;
}
