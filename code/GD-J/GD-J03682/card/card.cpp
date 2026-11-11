#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
int a[N];
int lst[N];
//int tr[N];
//void update(int p,int val){
//	while(p<=n){
//		tr[p]+=val;
//		p=p+(p&-p);
//	}
//}
//int query(int p){
//	int sum=0;
//	while(p){
//		sum+=tr[p];
//		p=p-(p&-p);
//	}
//	return sum;
//}
bool vis[N];
int ans[N],cnt[N];
void dfs(int p,int sum){
	//cout<<p<<' '<<sum<<' ';
	ans[a[p]]+=sum;
	if(p==n){
		//cout<<'\n';
		vis[a[p]]=true;
		return;
	}
	if(vis[a[p]]){
		//cout<<1<<'\n';
		dfs(lst[a[p+1]],sum);
		return;
	}
	vis[a[p]]=true;
	//cout<<2<<'\n';
	dfs(lst[a[p+1]],sum+cnt[a[p]]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis,false,sizeof(vis));
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		cnt[a[i]]++;
		ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			dfs(lst[i],0);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
