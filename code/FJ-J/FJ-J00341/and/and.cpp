#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=2e5+5;
int n,m;
int a[MAXN];
int flag[MAXN];
int dfs_ans;
int ans;
void dfs(int idx,int flg){
	if(flg==m){
		ans=max(ans,dfs_ans);
		return;
	}
	for(int i=1;i<=n;i++)
		if(idx!=i&&flag[i]!=1){
			int tmp=dfs_ans;
			flag[i]=1;
			dfs_ans&=a[i];
			dfs(i,flg+1);
			dfs_ans=tmp;
			flag[i]=0;
		}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs_ans=a[i];
		dfs(i,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
