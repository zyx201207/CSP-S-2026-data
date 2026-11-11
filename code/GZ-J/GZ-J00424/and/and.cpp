//GZ-J00424 张云景 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m,ans;
void dfs(long long to,long long p,long long res){
	if(p==m){ans=max(res,ans);return;}
	if(res==0)return;
	if(to>n)return;
	for(int i=to+1;i<=n;i++){
		dfs(i,p+1,res&a[to]);
		dfs(i,p,res);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,4294967295);
	printf("%lld\n",ans);
	return 0;
}
