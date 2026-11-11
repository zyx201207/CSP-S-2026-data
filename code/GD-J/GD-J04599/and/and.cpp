#include<bits/stdc++.h>
using namespace std;
int n,m,a[2100001],ans;
bool f[2100001];
void dfs(int i,int cnt,int step){
	if(cnt>=m){
		ans = max(ans,step);
		return ;
	}
	for(int j=1;j<=n;j++){
		if(!f[j]){
			f[j] = true;
			dfs(j,cnt+1,step & a[j]);
			f[j] = false;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,2147483647);
	cout<<ans<<'\n';
	return 0;
}

