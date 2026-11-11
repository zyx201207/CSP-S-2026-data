#include<bits/stdc++.h>
using namespace std;
long long s[500002],n,m,a[500002],diff[500002],ans=1;
//Oct31==Dec25?
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		diff[i]=a[i]-a[i-1];
		s[i]=s[i-1]+diff[i]*(i-1);
		//cout<<diff[i]<<' ';
    }
    //cout<<endl;
    //for(long long i=1;i<=n;i++)cout<<s[i]<<' ';
    //cout<<endl;
    long long l=1;
    for(long long r=2;r<=n;r++){
    	while(s[r]-s[l]-(a[r]-a[l])*(l-1)>m&&l<r)l++;
    	ans=max(ans,r-l+1);
    	//printf("%d %lld %d %d\n",ans,1ll*(1ll*s[r]-1ll*s[l]-1ll*(a[r]-a[l])*(l-1)),l,r);
	}
	printf("%lld",ans);
	//10 3 1 2 4 5 7 8 9 11 12 12
	return 0;
}
