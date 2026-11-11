#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T; scanf("%d%d",&c,&T);
	while(T--){
		int n;ll d; scanf("%d%lld",&n,&d);
		int ans=0;
		for(int i=1;i<=n;i++){
			ll x; scanf("%lld",&x);
			a[i]=x;
		}
		int l=1,r=1;
		for(;l<=n;l++){
			int num=0;
			for(;r<=n;r++){
				if(a[r]-a[l]>=2*d) break;
				if(a[r]-a[l]>d){
					if(r-l+1<4) continue;
					if(r-l+1==4){
						ans++;
						
						continue;
					}
					int mid=(r-l+1)>>1;
					mid=l+mid-1;
					if((r-l+1)%2==1){
						int flag=0;
						for(int i=0;i<=2;i++){
							if(a[mid+i]-a[l]<=d&&a[r]-a[mid+i]<=d){
								flag++;
							}
						}
						if(flag==2){
							ans++;
						}
					}else{
						if(a[mid-1]-a[l]<=d&&a[r]-a[mid-1]<=d) continue;
						if(a[mid+2]-a[l]<=d&&a[r]-a[mid+2]<=d) continue;
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
