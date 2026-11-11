#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],a[2000005],su,ans;
bool f;
void dfs(long long step,long long w,long long e){
	if(step>w){
		if(a[w]==e) f=true,su++;
		return;
	}
	for(int i=a[step-1]+1;i<=n;i++){
		if(abs(x[i]-x[a[step-1]])<=d){
			a[step]=i;
			dfs(step+1,w,e);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[1]=i;
				su=0,f=false;
				for(int k=2;k<=n;k++){
					dfs(2,k,j);
					if(f==true){
						if(su==2) ans++;
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
