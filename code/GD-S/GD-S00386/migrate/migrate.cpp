#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,a[N],c,ans,d;
int v[N],v2[N],cc[N],cnt;
inline void dfs(int x,int dd){
	if(v[x]&&dd==v[x]&&!v2[x])
		ans++,v2[x]=1;
		if(v[x]!=0)
	v[x]=min(v[x],dd);
	else v[x]=dd;
	for(int i=n;i>x;i--)
		if(a[i]-a[x]<=d)
			dfs(i,dd+1);
//		else break;
	return;
}
inline void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)v[j]=0,v2[j]=0;
		dfs(i,1);
//		sort(cc+1,cc+cnt+1);
//		for(int j=1;j<=n;j++){
//			if()
//		}
	}
	cout<<ans<<'\n';
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
cin>>c;
	int T;
	cin>>T;
	while(T--)
	solve();
	return 0;
}

