#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	long long y=0,l=1,r=1;
	while(r<n){
		r++;
		y+=(a[r]-a[r-1])*(r-l);
		if(y<=m){
			ans=max(ans,r-l+1);
		}
		else{
			while(y<=m){
				y-=(a[r]-a[l]);
				l++;		
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
