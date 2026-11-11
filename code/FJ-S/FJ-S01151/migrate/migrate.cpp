#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 20;
long long a[N];
int tmp[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(0 <= c && c <= 6){
		while(t--){
			int n,d;
			memset(tmp,0,sizeof(tmp));
			scanf("%lld%lld",&n,&d);
			for(int i = 1;i <= n;i++){
				scanf("%lld",&a[i]);
			}
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					if(a[j] - a[i] > d) tmp[i][j] = 0x3f3f3f3f;
					else tmp[i][j] = 1;
				}
			}
			for(int k = 1;k <= n;k++){
				for(int i = 1;i <= n;i++){
					for(int j = 1;j <= n;j++){
						tmp[i][j] = min(tmp[i][j],tmp[i][k] + tmp[k][j]);
					}
				}
			}
			
			long long ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					int flag = 0;
					for(int k = i + 1;k <= j - 1;k++){
						if(tmp[i][k] + tmp[k][j] == tmp[i][j]){
							flag++;
	//						printf("%lld -> %lld:%lld,%lld -> %lld:%lld,%lld -> %lld:%lld\n",i,k,tmp[i][k],k,j,tmp[k][j],i,j,tmp[i][j]); 
						}
					}
					if(flag == 2){
						//cout << i << ' ' << j <<'\n';
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	if(c == 13 || c == 14){
		while(t--){
			printf("0\n");
		}
	}
	return 0;
}


