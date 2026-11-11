#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcnt[2000005],rcnt[2000005],x[2000005],d,n,c,t;
ll ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(lcnt,0,sizeof(lcnt));
		memset(rcnt,0,sizeof(rcnt));
		memset(x,0,sizeof(x));
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int l=1,r=1;r<=n;r++){
			while(x[r]-x[l]>d)l++;
			lcnt[r]=r-l;
		}
		for(int l=n,r=n;l>0;l--){
			while(x[r]-x[l]>d) r--;
			rcnt[l]=r-l;
		}
		for(int i=1,cur=0,fut=0;i<=n;i++){
			if(rcnt[i]==0){
				fut=0;
				cur=0;
			}
			if(rcnt[i]==1){
				fut++;
				ans+=cur;
			}
			if(rcnt[i]>=2){
				i+=rcnt[i]-1;
				if(lcnt[i+rcnt[i]]>rcnt[i])break;
				i+=rcnt[i];
				cur=fut+1;
				fut=0;
				ans+=cur;
			}
		}
		printf("%lld\n",ans);
	}
}
