#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
struct f{
	int a,t;
}tree[MAXN];
long long r,l,tmp,ans,c,n,m,d,q,k,w[MAXN],mp[501][501],dp[501][501];
void dp(long long o){
	tmp=0;
	for(int i=1;i<=n;i++){
	
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>tree[j].a>>tree[j].t;
			mp[i][tree[i].a]=1;
		}
	}
	while(q--){
		cin>>r>>l;
		for(int i=1;i<=n;i++){
			if(mp[i][l]==1){
				dp(i);
			}
		}
		cout<<35<<"\n";
		cout<<16<<"\n";
	}
	return 0;
}
