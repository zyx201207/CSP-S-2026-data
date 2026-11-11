#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[400000],n,m,maxn;
void dfs(LL cur,LL pre,LL num){
	if(cur==n+1){
		maxn=max(maxn,num);
		return ;
	}
	for(LL i=pre+1;i<=n;i++){
		dfs(cur+1,i,num&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	for(LL i=1;i<=n;i++) dfs(2,1,a[i]);
	cout<<maxn;
	return 0;
}
