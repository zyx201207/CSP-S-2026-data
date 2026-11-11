#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+4;
int c,T,n,m,pre[N],nxt[N],cnt[N];
ll a[N],k,ans,cur[N];
vector<int> e[N];
int search1(ll val){
	int l=1,r=n,mid,anss;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>val) r=mid-1;
		else l=mid+1,anss=mid;
	}
	return anss;
}
int search2(ll val){
	int l=1,r=n,mid,anss;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>=val) r=mid-1;
		else l=mid+1,anss=mid;
	}
	return anss;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d %lld",&n,&k);
		ll ans=0;
		for(int i=1; i<=n; i++){
			scanf("%lld",&a[i]);
			cur[i]=0;
		}
		for(int i=1; i<=n; i++){
			int l=search2(a[i]-k)+1,r=search1(a[i]+k);
			pre[i]=l,nxt[i]=r;
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(pre[j]==nxt[i]-1){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

