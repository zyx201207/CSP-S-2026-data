#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
vector<int>e;
int n,m,a[N],ans;
void dfs(int step,int sum,int lj){
	if(lj==m){
		e.push_back(sum);
		return;
	}
	for(int i=step+1;i<=n-m+step+1;i++){
		dfs(i,sum&a[i],lj+1);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(int i=1;i<=n-m+1;i++)	dfs(i,a[i],1);
	for(int i=0;i<(int)e.size();i++)	ans=max(ans,e[i]);
	printf("%lld",ans);
	return 0;
}
