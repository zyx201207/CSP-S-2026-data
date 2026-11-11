#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[200005],ans,tr[6000005][2],tot/*,cnt[6000005]*/;
bool vis[200005];
//void insert(int x){
//	int p=0;
//	cout<<"insert: ";
//	for(int i=29;i>=0;i--){
//		int c=(x>>i)&1;
//		cout<<c;
//		if(!tr[p][c]) tr[p][c]=++tot;
//		p=tr[p][c];
//		cnt[p]++;
//	}
//	cout<<'\n';
//}
//int solve(){
//	int p=0,c=0,i=30,res=0;
//	for(int i=30;i>=0;i--){
//		cout<<"i c p: "<<i<<' '<<c<<' '<<p<<'\n';
//		res+=(c<<i);
//		cout<<cnt[tr[p][1]]<<'\n';
//		if(cnt[tr[p][1]]>=m&&tr[p][1]) cout<<"ppp\n",c=1;
//		else c=0;
//		p=tr[p][c];
//	}
//	return res;
//}
void dfs(int i,int cnt,int res){
	if(cnt==m){
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,cnt+1,res&a[i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=n;i++) cin>>a,insert(a);
//	int p=tr[0][0];
//	while(p<=tot&&p){
//		if(!tr[p][1]) p=tr[p][0];
//		else p=tr[p][1],cout<<cnt[p]<<' ';
//	}
//	cout<<'\n';
//	cout<<solve();
	dfs(1,0,(~0));
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
