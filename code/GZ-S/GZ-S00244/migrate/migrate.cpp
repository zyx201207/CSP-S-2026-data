//GZ-S00244 遵义市第四中学 罗永淇 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+4;
const long long MX=2e18+2;
long long a[N],dp[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,hp;
		scanf("%d%d",&n,&hp);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			dp[i]=a[i]-a[i-1];
		}
		dp[n+1]=MX;
		for(int i=1;i<=n-3;i++){
			int s=0;
			for(int j=i+1;j<=n;j++){
				s+=dp[j];
				if(s>=hp){
					if(j==i+3&&s<2*hp&&hp<s){
						ans++;
					}else if(j==i+2&&hp>=dp[j+1]&&hp<s+dp[j+1]&&j+1<=n){
						ans++;
						break;
					}else break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

