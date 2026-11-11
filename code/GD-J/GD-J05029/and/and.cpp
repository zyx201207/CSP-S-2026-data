#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m;
long long a[N];
long long maxn=0;
void dfs(int d,int x,long long cnt){
	if(d>m) return ;
	if(d==m) maxn=max(maxn,cnt);
	for(int i=x+1;i<=n;i++){
		if(d==0) dfs(d+1,i,a[i]);
		else dfs(d+1,i,a[i]&cnt);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(0,0,0);
	cout<<maxn;
	return 0;
}
