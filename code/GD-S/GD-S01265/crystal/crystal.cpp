#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n,m,a[N],ma=LLONG_MIN,mi=LLONG_MAX,cnt;
bool cheak(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)ans+=x-a[i];
	}if(ans<=m)return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}int l=mi-1,r=ma+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(cheak(mid))l=mid;
		else r=mid;
	}for(int i=1;i<=n;i++){
		if(a[i]<=l)cnt++;
	}printf("%lld",cnt);
	return 0;
} 
