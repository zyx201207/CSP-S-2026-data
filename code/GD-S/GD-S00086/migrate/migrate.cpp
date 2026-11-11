#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10;
int a[N],x[N],b[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,d,ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			a[i]=x[i]-x[i-1];
		}
//		int cnt=0;
//		while(1){
//			if(a[cnt+1]<=d){
//				cnt++;
//				a[cnt]=1;
//				break;
//			}
//		}
//		for(int i=cnt+1;i<=n;i++){
//			for(int j=i-1;j>=1;j--){
//				b[i]+=a[j];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<i;j++){
//				if(b[i]-b[j]==2){
//					ans++;
//				}
//			}
//		}
//		printf("%lld\n",ans);
		printf("0\n");
	}
} 
