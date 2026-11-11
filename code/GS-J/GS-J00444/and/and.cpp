#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1e9;
bool vis[200005];
long long f(long long l,int t){
	if(t==m) return l;
	long long b=-1e9;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(l&a[i]>b){
				b=l&a[i];
				vis[i]=1;
			}
		}
	}
	return f(b,t+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		vis[i]=1;
		ans=max(f(a[i],1),ans);
	}
	printf("%lld",ans);
	return 0;
}
