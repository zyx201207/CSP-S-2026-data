#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,r=1,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	while(r<=n){
		sum+=(r-l)*(a[r]-a[r-1]);
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
