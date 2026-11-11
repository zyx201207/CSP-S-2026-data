//遵义市新蒲新区滨湖中学 金卓承 GZ-J00442 
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,a[100000005],maxn;
void dfs(ll s,ll id,ll g){
	//cout<<a[id]<<' '<<s<<endl;
	if(id>n||g>m) return;
	if(g==m){
		
		maxn=max(maxn,s);
		return;
	}
	dfs(s&a[id+1],id+1,g+1);
	dfs(s,id+1,g);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) dfs(a[i],i,1);
	printf("%lld",maxn);
	return 0;
}
