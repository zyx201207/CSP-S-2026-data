#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
void dfs(long long x,long long pos,long long cnt){
	if(x>m){
		ans=max(cnt,ans);
		return;
	}
	for(long long i=pos+1;i<=n-m+x+1;i++){
		dfs(x+1,i,cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n-m+1;i++){
		dfs(1,i,a[i]);
	}
	cout<<ans;
	return 0;
}
