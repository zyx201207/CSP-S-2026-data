#include<bits/stdc++.h>
#define ll long long
ll c,T,n,d,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a[i]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				vector<int> l;
				l.clear();
				int u=i;
				for(int t=u+1;t<=j;t++){
					if(a[t]>a[u]+d){
						lj.push_back(t-1);
						u=t-1;
					}
				}
				if(a[lj[lj.size()-1]]+d<a[j]){
					break;
				}else{
					
				}
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
}
