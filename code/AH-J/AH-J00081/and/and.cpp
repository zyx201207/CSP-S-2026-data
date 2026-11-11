#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long pos=n;
	while(a[pos]&a[pos-1]==0&&pos>m){
		pos--;
	}
	long long xum=a[pos];
	for(long long i=pos-1;i>=pos-m+1;i--){
		xum=xum&a[i];
	}
	printf("%lld",xum);
	return 0;
}
