#include<bits/stdc++.h> 
using namespace std;
const int N=300000;
long long a[N],ans,b[N],n,m;
bool v[N];
void dfs(int deep){
	if(deep>m){
		long long u=a[1];
		for(int i=2;i<=m;i++){
			u&=a[i];
		}
		ans=max(ans,u);
	}
	for(long long i=1;i<=n;i++)
		if(!v[i]){
			v[i]=true;
			a[deep]=b[i];
			dfs(deep+1);
			v[i]=false;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&b[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
