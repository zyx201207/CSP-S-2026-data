#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=5e5+20;
int n;
ll m;
ll a[N];
__int128 sum[N];

bool check(int l,int r){
	__int128 Z=(__int128)1*a[r]*(r-l+1);
	__int128 P=sum[r]-sum[l-1];
	if(Z-P>(__int128)m)return 0;
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d %lld",&n,&m);
	rep(i,1,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		int id=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				id=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-id+1);
	} 
	printf("%d\n",ans);
	return 0;
}
