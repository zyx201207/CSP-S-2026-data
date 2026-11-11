#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500069],ans;

int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
		scanf("%lld%lld",&n,&m);
	cout<<n<<m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long l=i-1,las=m;
		while(l>=1&&a[i]-a[l]<=las){
			las-=a[i]-a[l];
			l--;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
