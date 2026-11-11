#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],n,m,pre[N];
bool check(int l,int r){
	int sum=pre[r]-pre[l-1];
	int targ=a[r]*(r-l+1);
	return targ-sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1,res=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld\n",ans);
} 
