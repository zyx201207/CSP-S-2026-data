//GZ-S00310 遵义市第十九中学  戴文博 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ch[500010];
long long sum1[500010];
long long sum2[500010];
bool check(int size){
	long long cnt=0;
	for(int i=2;i+size-1<=n;i++){
		cnt=size*sum1[i+size-1]-(sum2[i+size-2]-sum2[i-2]);
		if(cnt<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ch[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		sum1[i]=sum1[i-1]+ch[i];
	}
	for(int i=2;i<=n;i++){
		sum2[i]=sum2[i-1]+sum1[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid+1;
		}else{
			r=mid;
		}
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}

