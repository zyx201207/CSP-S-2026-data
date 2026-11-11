#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
using LL = long long;
const LL N = 2e5 + 5;

LL n,m,a[N],ans;
void dfs(LL cur,LL cnt,LL val){
	if(cur>n){
		if(cnt==m)	ans=max(ans,val);
		return ;
	}
	dfs(cur+1,cnt+1,val&a[cur]);
	dfs(cur+1,cnt,val);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++)	{
		scanf("%lld",&a[i]);
	}
	if(m<=30){	dfs(1,0,2147483647);printf("%lld",ans);}
	else{
	sort(a+1,a+1+n);
	printf("%lld",a[n-m+1]);
	}

	return 0;
}
