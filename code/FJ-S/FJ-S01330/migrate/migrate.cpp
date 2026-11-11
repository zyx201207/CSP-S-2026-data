#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef double D;
typedef long long LL;
typedef unsigned long long ULL;
const int N=1e4+10;
const int N2=1e9+10;
LL c,t,n,d,ans;
LL x[N];
LL mp[N][N],cnt[N][N];
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(LL _=1;_<=t;_++){
		ans=0;
		memset(x,0,sizeof(x));
		memset(cnt,0,sizeof(cnt));
		scanf("%lld%lld",&n,&d);
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=n;j++){
				if(i!=j){
					mp[i][j]=N;
				}
			}
		}
		for(LL i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(LL j=i;j>=0;j--){
				mp[i][j]=mp[j][i]=(x[i]-x[j])<=d?1:N;
			}
		}
		for(LL k=1;k<=n;k++){
			for(LL i=1;i<n;i++){
				for(LL j=i+1;j<=n;j++){
					if(mp[i][j]>mp[i][k]+mp[k][j]){
						cnt[i][j]=1;
						mp[i][j]=mp[i][k]+mp[k][j];
					}
					else if(mp[i][j]==mp[i][k]+mp[k][j]){
					 	cnt[i][j]++;
					}
				}
			}
		}
		for(LL i=1;i<n;i++){
			for(LL j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}

