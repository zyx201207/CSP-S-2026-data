#include<bits/stdc++.h>
#define lll long long
using namespace std;
int n,ans=1;
lll m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1;lll k=0;
	for(int i=2;i<=n;i++){
		k+=(i-l)*(a[i]-a[i-1]);
		if(k>m){
			while(k>m) k-=a[i]-a[l++];
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
