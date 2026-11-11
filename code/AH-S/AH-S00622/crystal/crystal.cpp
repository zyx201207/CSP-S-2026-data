#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long l=1,r=1,c=0;
	while(r<=n){
		while(c<=m){
			r++;
			c=c+(r-l+1)*(long long)(a[r]-a[r-1]);
			ans=max(r-l+1,ans);
			if(r>=n){
				break;
			}
		}
		while(c>m){
			c=c-(a[r]-a[l]);
			l++;
			if(l>=r){
				break;
			}
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
