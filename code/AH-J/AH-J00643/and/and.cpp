#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[200005];
LL ans[200005],maxn;
void print(){
	LL x=ans[0];
	for(LL i=1;i<m;i++){
		x&=ans[i];
	}
	maxn=max(maxn,x);
}
void dfs(LL cur,LL pos){
	if(cur==m){
		print();
		return ;
	}
	for(LL i=pos+1;i<=n;i++){
		ans[cur]=a[i];
		dfs(cur+1,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
