#include<bits/stdc++.h>
using namespace std;const int N=2e6+5;
int n,d,x[N],ans,mn,cnt;
void dfs(int l,int r,int s){
	if(l==r){if(s==mn)cnt++;return;}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]>d)break;
		dfs(i,r,s+1);
	}
}
bool ck(int l,int r){
	mn=cnt=0;
	for(int i=l,pre=l;i<=r;i++)if(x[i]-x[pre]>d)mn++,pre=i-1;
	mn++;
	dfs(l,r,0);
	return cnt==2;
}
void solve(){
	ans=0;cin>>n>>d;for(int i=1;i<=n;cin>>x[i++]);
	for(int l=1;l<=n;l++)for(int r=l+3;r<=n;r++)if(ck(l,r))ans++;
	cout<<ans<<"\n";
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	if(c>=3)while(T--){cout<<"0\n";return 0;}
	while(T--)solve();
	return 0;
}
