#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,maxx=-1e14,ans=-1e14;
long long andl,ands;
long long a[200005];
long long sum[200005];
bool f=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(pow(2,(int)log2(a[i]+1))-1!=a[i]){
			f=0;
		}
		ans=max(ans,a[i]);
	}
	andl=a[1];
	for(int i=2;i<=n;i++){
		andl=andl&a[i];
	}
	if(m==1){
		printf("%lld",ans);
		return 0;
	}
	else if(m==n){
		printf("%lld",andl);
		return 0; 
	}
	else if(f==1){
		sort(a+1,a+n+1);
		ands=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ands=ands&a[i];
		}
		printf("%lld",ands);
		return 0;
	}
	else{
		for(int l=1;l<=n-m;l++){
			cnt=a[l];
			for(int i=l;i<=l+m-1;i++){
				cnt=cnt&a[i];
			}
			maxx=max(cnt,maxx);
		}
		printf("%lld",maxx);
	}
	return 0;
}
