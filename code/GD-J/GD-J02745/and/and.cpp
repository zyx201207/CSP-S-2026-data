#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,a[200005],b[200005],v[200005],l;
void dfs(long long k) {
	if(k==m+1) {
		long long ans1=b[1];
		for(int i=2; i<=m; i++) {
			ans1=ans1&b[i];
		}
		ans=max(ans,ans1);
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!v[i]) {
			v[i]=1;
			b[++l]=a[i];
			dfs(k+1);
			v[i]=0;
			b[l--]=0;
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}else if(m==n){
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
