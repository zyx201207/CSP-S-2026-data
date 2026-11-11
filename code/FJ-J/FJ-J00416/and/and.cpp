#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
}
