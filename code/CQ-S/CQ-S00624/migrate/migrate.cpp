#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int c,t,n,d,x[maxn],cnt[maxn];
void dfs(int l,int r,int now){
	if(l==r){
		cnt[now]++;
		return ;
	}
	for(int i=l+1;i<=r;++i){
		if(abs(x[l]-x[i])<=d) dfs(i,r,now+1);
	}
}
inline bool check(int l,int r){
	for(int i=1;i<=n;++i) cnt[i]=0;
	dfs(l,r,0);
	for(int i=1;i<=n;++i){
		if(cnt[i]!=0){
			if(cnt[i]==2) return 1;
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j) ans+=check(i,j);
		}
		cout<<ans<<'\n';
	}
}
