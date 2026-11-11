#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N],c[N],d[N];
long long check(int l,int r){
	int len=r-l+1;
	return (len-1)*b[r]-c[r-1]+c[r-len];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) b[i]=d[i]+b[i-1];
	for(int i=1;i<=n;i++) c[i]=b[i]+c[i-1];
	long long ans=1;
	for(long long i=1;i<=n;i++){
		if(i==1) continue;
		long long l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)>m){
				l=mid+1;
			}
			else if(check(mid,i)<m){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}
			else if(check(mid,i)==m){
				ans=max(ans,i-mid+1);
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
