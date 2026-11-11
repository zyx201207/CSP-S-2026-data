#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=1,t=0;
	while(r<=n){
		if(t<m){
			r++;
			t+=(a[r]-a[r-1])*(r-l);
		}else{
			l++;
			t-=a[r]-a[l-1];
		}
		if(t<=m){
			ans=max(ans,r-l+1);
		}
	}
	printf("%lld",ans);
	return 0;
}
