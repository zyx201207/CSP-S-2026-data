//GZ-J00512 易煊培 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long m,n,a[200010]={0},ans=-1,b[200010]={0};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++) scanf("%lld",&a[i]);
	for(long long i=1;i<=(1<<n);i++){
		long long cnt=0,yu=-1;
		for(long long j=0;j<n;j++){
			if(i&(1<<j)) {
				b[cnt]=a[j];
				cnt++;
			}
		}
		if(cnt==m){
			yu=b[0];
			for(long long j=1;j<m;j++){
				yu=(yu&b[j]);
			}
			ans=max(ans,yu);
		}
	}
	printf("%lld",ans);
	return 0;
}  
