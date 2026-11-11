#include<bits/stdc++.h>
using namespace std;
int n,x=2,ans=0;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n&&x<=n;i++){
		while((x-i)*(a[x]-a[x-1])<=m&&x<=n){
			m-=(x-i)*(a[x]-a[x-1]);
			x++;
		}
		ans=max(ans,x-i);
		m+=a[x-1]-a[i-1];
	}
	printf("%d",ans);
	return 0;
}
