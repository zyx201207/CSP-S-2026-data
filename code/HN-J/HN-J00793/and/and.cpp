#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void dfs(long long k,long long cnt,long long sum){
	if(cnt>m)return;
	if(cnt+n-k+1<m)return;
	if(cnt!=0&&sum<=ans)return;
	if(k==n+1){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(k+1,cnt,sum);
	if(cnt==0)dfs(k+1,cnt+1,a[k]);
	else dfs(k+1,cnt+1,(sum&a[k]));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
