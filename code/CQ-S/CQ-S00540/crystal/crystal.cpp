#include<bits/stdc++.h>
#define fre(ss,i,j,k) for(int ss=i;ss<=j;ss+=k)
#define rep(ss,i,j,k) for(int ss=i;ss>=j;ss-=k)
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	fre(i,1,n,1)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	fre(i,1,n,1)sum[i]=sum[i-1]+a[i];
	fre(i,1,n,1){
		int l=1,r=i,an=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
				an=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-an+1);
	}
	printf("%d",ans);
	return 0;
}
