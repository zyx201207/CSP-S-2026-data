#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
long long a[500010],pre[500010];
bool f=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) f=false;
	}
	sort(a+1,a+n+1);
	if(f==true){
		pre[1]=a[1];
		for(long long i=2;i<=n;i++){
			pre[i]=a[i]+pre[i-1];
		}
		for(long long i=n;i>=1;i--){
			if(m>=pre[i-1]){
				printf("%lld",i);
				return 0;
			}
		}
	}
	for(long long i=n;i>=1;i--){
		sum=0;
		for(long long j=1;j<i;j++){
			sum+=a[i]-a[j];
		}
		if(sum<=m){
			printf("%lld",i);
			break;
		}
	}
	
	return 0;
}
