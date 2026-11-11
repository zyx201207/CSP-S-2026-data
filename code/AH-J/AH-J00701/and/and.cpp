#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[200010],maxn=0,sum=0;
void dfs(LL p,LL cur,LL sum){
	if(cur>m) maxn=max(maxn,sum);
	if(sum<=maxn) return ; 
	for(LL i=p;i<=n-m+cur;i++){
		dfs(i+1,cur+1,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==m){
		maxn=a[1];
		for(LL i=2;i<=n;i++) maxn&=a[i];
		cout<<maxn;
		return 0;
	}
	if(m==1){
		for(LL i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	for(LL i=1;i<=n-m+1;i++) dfs(i+1,2,a[i]);
	cout<<maxn;
	return 0;
}
