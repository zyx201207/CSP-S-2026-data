#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans=0;
void dfs(int i,int d,long long sum){
	if (d==m){
		ans=max(ans,sum);
		return;
	}
	for (int j=i;j<=n;j++){
		dfs(i+1,d+1,sum&a[i+1]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		long long maxn=0;
		for (int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}cout<<maxn;
		return 0;
	}
	else if (m==n){
		long long maxn=a[1];
		for (int i=2;i<=n;i++){
			maxn&=a[i];
		}cout<<maxn;
		return 0;
	}
	else{
		dfs(1,1,a[1]);
		cout<<ans;
	}
	return 0;
}
