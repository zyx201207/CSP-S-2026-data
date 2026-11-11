#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n;
LL a[N],m;
__int128 sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=-1;
		while(l<=r){
			int mid=l+r>>1;
			if((__int128)a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=(__int128)m){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%d",ans);
	return 0;
}