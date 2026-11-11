#include <bits/stdc++.h>
using namespace std;
//vesna & danica
int a[100010];
#define int long long
signed main(){
	int c,t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int n,d;
		scanf("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				vector<int> best;
				int p=i;
				best.push_back(i);
//				printf("%d %d:",i,j);
				while(true){
					int jump=0;
					while(jump+p<=n && a[p+jump]-a[p]<=d){
						jump++;
					}
//					printf("%d;",jump);
					if (jump+p>j){
						best.push_back(j);
						break;
					}
					if (jump<=1){
						break; 
					}
					p+=jump-1;
					best.push_back(p);
				}
				if (best.back()!=j){
					continue;
				}
//				for (int i:best){
//					printf("%d ",i);
//				}
//				printf("%d\n",best.size());
				int flag=0;
				for (int k=0;k<((int)best.size()-2);k++){
//					printf("%d %d %d\n",(int)best.size()-2,k,k>=best.size()-2);
					for (int l=best[k]+1;l<=best[k+2]-1;l++){
//						printf("%d %d\n",l,best[k]);
						if (l!=best[k+1] && a[l]-a[best[k]]<=d && a[best[k+2]]-a[l]<=d){
							flag++;
						}
					}
				}
				if (flag==1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
				
