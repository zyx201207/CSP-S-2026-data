//(^-^)
#include<bits/stdc++.h>
#define ll long long
#define N 2000050
using namespace std;
ll c,t,n,d,a[N],mi[N],ct[N],ans;
void dfs(ll fr,ll to,ll ti){
	if (mi[to]==0||mi[to]>ti) {
		mi[to]=ti;
		ct[to]=ct[fr];
		for (int i=to+1;i<=n;i++) {
			if (a[i]-a[to]>d) break;
			dfs(to,i,ti+1);
		}
	}else if (mi[to]==ti) {
//		cout<<fr<<' '<<to<<'\n';
		ct[to]+=ct[fr];
	}
}
void f(){
	cin>>n>>d;
	ans=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++) {
		for (int j=1;j<=n;j++) mi[j]=ct[j]=0;
		ct[i]=1;
		for (int j=i+1;j<=n;j++) {
			if (a[j]-a[i]>d) break;
			dfs(i,j,1);
		}
		for (int j=1;j<=n;j++) {
			if (ct[j]==2) ++ans;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++) f();
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13


*/
