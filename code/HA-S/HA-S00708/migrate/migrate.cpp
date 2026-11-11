#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000010],b[2000010],k,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i]-a[1];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(b[j]-b[j-1]>d){
					i=j;
					break;
				}
				if(b[j]-b[i]>d){
					k=(b[j]-b[i])/d+(b[j]-b[i])%d;
					if(k==2&&b[j]-b[i]==2*d-1){
						ans++;
					} 
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
