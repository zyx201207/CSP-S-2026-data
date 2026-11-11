#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
long long cha[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		
	}
	sort(a+1,a+n+1);
//	for(long long i=1;i<=n;i++){
//		cha[i]=a[i]-a[i-1];	 
//	}
//	int f=0;
//	for(int i=2;i<=n;i++){
//		if(cha[i]==cha[i-1]){
//			f++;
//		}
//	}
//	if(f==n-1){
//		printf("%lld",m/cha[2]-cha[1]);
//		return 0;
//	}
	for(long long i=2;i<=n;i++){
		long long cnts=0,cnt=0;
		for(long long j=i-1;j>=1;j--){
			cnt=cnt+(a[i]-a[j]);
			cnts++;
			if(cnt==m){
				break;
			}else if(cnt>m){
				cnts--;
			}
		}
		ans=max(ans,cnts+1);
	}
	printf("%lld",ans);
	return 0;
}
