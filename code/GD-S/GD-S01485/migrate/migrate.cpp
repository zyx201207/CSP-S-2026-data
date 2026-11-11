#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int c,t,n,d,a[N],ans,dis[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c<=10){
			for(int l=1;l<=n;l++){
				vector<int>cc;
				dis[l]=0;
				cnt[l]=1;
				int i=1;
				cc.push_back(1); 
				for(int r=l+1;r<=n;r++){
					while(a[i]<a[r]-d){
						cc[dis[i]]-=cnt[i];
						i++;
					}
					if(i==r){
						break;
					}
					dis[r]=dis[i]+1;
					cnt[r]=cc[dis[i]];
					cnt[r]=min(cnt[r],3ll);
					while(dis[r]>=cc.size()){
						cc.push_back(0);
					}
					cc[dis[r]]+=cnt[r];
					if(cnt[r]==2){
						ans++;
					}
					if(cnt[r]==0){
						break;
					}
				}
			}
		}else{
			int x=d/(a[2]-a[1]);
			if(x<=1){
				ans=0;
			}else{
				ans=max(n-2*x+1,0ll);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
