#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,
	far[N],cnt[N],pre[N],suf[N];
ll d,ans,
	x[N];
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i)pre[i]=0;
	for(int i=1;i<=n;++i)cin>>x[i];
	x[0]=-INF,x[n+1]=INF;
	for(int i=1,j=1;i<=n;++i){
		while(x[j]-x[i]<=d)j++;
		far[i]=j-1;
		cnt[i]=1;
	}
	for(int i=n,j=n;i;--i){
		while(x[i]-x[j]<=d)j--;
		pre[i]=j+1;
		suf[i]=1;
	}
	for(int i=n;i>=2;--i){
		int j=pre[i];
		if(pre[i]==pre[j+1])suf[j]+=suf[i];
	}
	for(int i=1;i<n;++i){
		int j=far[i];
		if(j==i)continue;
		if(far[i]==far[j-1])cnt[j]+=cnt[i];
		else ans+=1ll*cnt[i]*suf[far[j-1]]*(far[j-1]-far[j-2]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
