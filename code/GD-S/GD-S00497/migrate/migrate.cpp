#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int N=2e6+7;
int c,T,n;
ll d,a[N],dis[N],cnt[N],ans;
void clear(){
	ans=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		clear();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c<=10){
			for(int l=1;l<=n;l++){
				vector<ll> Cnt;
				dis[l]=0;cnt[l]=1;
				int L=l;Cnt.push_back(1); 
				for(int r=l+1;r<=n;r++){
					while(a[L]<a[r]-d) Cnt[dis[L]]-=cnt[L],++L;
					if(L==r) break;
					dis[r]=dis[L]+1;
					cnt[r]=Cnt[dis[L]];
					cnt[r]=min(cnt[r],3ll); 
	//				printf("%d %d %d %lld %lld %d\n",l,L,r,cnt[r],dis[r],Cnt.size());
					while(dis[r]>=Cnt.size()) Cnt.push_back(0);
					Cnt[dis[r]]+=cnt[r];
	//				Cnt[dis[r]]=min(Cnt[dis[r]],3);
					if(cnt[r]==2) ++ans;
					if(cnt[r]==0) break;
				}
			}
		}
		else{
			ll x=d/(a[2]-a[1]);
			if(x<=1) ans=0;
			else ans=max(n-2*x+1,0ll);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
