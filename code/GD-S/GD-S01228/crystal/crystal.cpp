#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<r && sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,(long long)r-l+1);
	}
	cout<<ans;
	return 0;
}
