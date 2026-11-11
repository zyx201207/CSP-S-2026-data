#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll c,t,n,d,arr[N],sum[N],L[N],dis[N];
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate1.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&d);
		ll gc=0;
		arr[0]=-9.223e18;
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
			if(i==1)continue;
			L[i]=lower_bound(arr+1,arr+i,arr[i]-d)-arr;
		}
		ll cnt=0;
		for(int l=1;l<=n;l++){
			sum[l]=1;
			dis[l]=0;
			for(int r=l+1;r<=n;r++){
				sum[r]=0;
				ll x=max((ll)l,L[r]);
				ll mn=1e9;
				for(int j=x;j<r;j++){
					mn=min(mn,dis[j]+1);
				}
				if(mn==1e9)break;
				dis[r]=mn;
				//printf("%lld %lld:%lld,",l,r,mn);
				for(int j=x;j<r;j++){
					if(dis[j]+1==mn){
						//printf("%lld->%lld",j,r);
						sum[r]+=sum[j];
					}
				}
				//printf("%lld\n",sum[r]);
				if(sum[r]==2)cnt++;
				//else if(sum[r]>2)break;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
