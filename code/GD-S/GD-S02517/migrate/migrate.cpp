#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,x[2000005];
int ans=0,c,t,f1[2000005],f2[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		if(c==11||c==12){
			ll c=x[2]-x[1];
			ll k=(ll)(d/c);
			ll ans=n-2*k+1;
			ans=max(ans,0ll);
			if(d<c||k==1) ans=0;
			printf("%lld\n",ans);
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int p=i,cnt=0;
					for(int k=i;k<=j;k++){
						f1[k]=0;
						if(x[k+1]-x[p]>d) p=k,f1[k]=1;
					}
					if(p==i) continue;
					p=j; 
					for(int k=j;k>=i;k--){
						f2[k]=0;
						if(x[p]-x[k-1]>d){
							p=k,f2[k]=1;
							if(f1[k]==0){
								if(f1[k-1]==0&&f1[k+1]==0){
									break;
								}else{
									cnt++;
								}
							}
						}
					}
					if(cnt==1) sum++;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
