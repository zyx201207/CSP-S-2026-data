#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum=0,f=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sum+=m;
	sum/=n;
	for(int i=1;i<=n;i++){
		if(a[i]>sum){
			f=i-1;
			break;
		}
	}
	for(int i=f;i>=1;i--){
		m=m-sum+a[i];
		ans++;
		if(m<=0){
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}
