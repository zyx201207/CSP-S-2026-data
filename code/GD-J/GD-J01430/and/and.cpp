#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200005],t;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	t=a[1];
	for(int i=2;i<=m;i++){
		t=(t&a[i]);
	}
	printf("%lld",t);
	return 0;
}

