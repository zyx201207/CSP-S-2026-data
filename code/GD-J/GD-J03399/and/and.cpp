#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],ans; 
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;++i){
		ans&=a[i];
	}
	printf("%lld",ans);
	return 0;
}

