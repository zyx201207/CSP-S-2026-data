#include<bits/stdc++.h>
using namespace std;
long long INF=LLONG_MIN/3;
long long n,m,anss=-1,ans=INF,a[200005],maxn=INF;
bool b[200005];
void dfs(int dep,int yixuan){
	if(dep>n){
		if(yixuan<m){
			return;
		}else{
			anss=INF;
			for(int i=1;i<=n;i++){
				if(b[i]){
					if(anss==INF){
						anss=a[i];
					}else{
						anss=anss&a[i];
					}
				}
			}
			ans=max(ans,anss);
		}
		return;
	}
	if(yixuan==m){
		dfs(dep+1,yixuan);
		return;
	}
	b[dep]=1;
	dfs(dep+1,yixuan+1);
	b[dep]=0;
	dfs(dep+1,yixuan);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		printf("%lld",maxn);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
					maxn=max(maxn,a[i]&a[j]);
			}
		}
		printf("%lld",maxn);
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
