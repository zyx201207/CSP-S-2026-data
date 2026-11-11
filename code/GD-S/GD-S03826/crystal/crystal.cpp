#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[600001],c[600001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		c[i]=c[i-1]+1LL*i*(a[i]-a[i-1]);
	}
	int l=0,r=1,ans=1;
	while(r<n){
		if(c[r]-c[l]-1LL*l*(a[r]-a[l])<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	printf("%d",ans);
	return 0;
}
