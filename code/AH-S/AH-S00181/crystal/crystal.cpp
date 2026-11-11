#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r=1,ans=-1;
long long m,now,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	while(r<=n){
		now=now+(a[r]-a[r-1])*(r-l);
		while(now>m&&l<r){
			l++;now=now-(a[r]-a[l]);
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans<<endl;
	return 0;
}
