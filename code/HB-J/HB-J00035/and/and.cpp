#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,aa=2147483647,maxn=0;
long long l[200010],r[200010];
void dfs(int t,long long j,int cnt){
	if(t==n){
		if(cnt==m) ans=max(ans,j);
		return;
	}if(cnt<m) dfs(t+1,j&a[t],cnt+1);
	dfs(t+1,j,cnt);
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i],aa&=a[i],maxn=max(maxn,a[i]);
	if(n<=20||m==2){
		dfs(0,2147483647,0);
		cout<<ans;
	}if(m==1) cout<<maxn;
	if(m==n) cout<<aa;
	if(m==n-1){
		l[0]=a[0];
		for(int i=1;i<n-1;i++){
			l[i]=l[i-1]&a[i];
		}r[n-1]=a[n-1];
		for(int i=n-2;i>=1;i--){
			r[i]=r[i+1]&a[i];
		}ans=max(l[n-2],r[1]);
		for(int i=1;i<n-1;i++){
			ans=max(ans,r[i+1]&l[i-1]);
		}cout<<ans;
	}return 0;
}
