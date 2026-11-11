#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int N=2e5+10;
int a[N];
int n,m;
bool cmp(int a,int b){
	return a>=b;
}
signed main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);	
	}	
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int j=2;j<=m;j++){
		ans&=a[j];
	}
	printf("%lld",ans);
	return 0;
}
