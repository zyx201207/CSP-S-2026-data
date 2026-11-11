#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void dfs(long long s,long long cnt,long long x){
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	if(s==n) return;
	dfs(s+1,cnt,x);
	x&=a[s+1];
	dfs(s+1,cnt+1,x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,LONG_LONG_MAX);
	cout<<ans;
}
