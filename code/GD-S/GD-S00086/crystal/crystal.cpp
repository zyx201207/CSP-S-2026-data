#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N],m; 
bool chk(int x,int y){
	int s=x-y+1;
	int sum1=sum[x]-sum[s-1];
	int cc=y*a[x]-sum1;
	if(cc<=m){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r+1)/2;
			if(chk(i,mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(!chk(i,r)){
			continue;
		}
		ans=max(ans,r);
	}
	printf("%lld",ans);
} 
