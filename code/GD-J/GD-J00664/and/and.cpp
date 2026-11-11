#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	long long a[n+5];
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=2; i<=m; i++){
		sum=sum&a[i];
	}
	printf("%lld",sum);
	return 0;
}
