#include <bits/stdc++.h> 
using namespace std;
const int N=2e6+78;
long long n,m,c,t,a[N],ans,minans=-1;
void dfs(long long x,long long step){
	for(int i=m;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(x+i==a[n]){
				if(minans!=-1&&step==minans){
					ans++;
				} 
				else {
					minans=step;
				}
				return;
			}
			if(x+i==a[j]){
				dfs(x+i,step+1);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			a[i]=a[i]-a[1];
		}
		dfs(0,1);
		printf("%lld\n",ans+1);
	}
	return 0;
}
