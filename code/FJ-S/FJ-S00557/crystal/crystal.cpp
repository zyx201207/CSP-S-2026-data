#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],um,w,su;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long li=1,ri=1,um=1;
	while(ri<n){
			w+=um*(a[ri+1]-a[ri]);
			um++;
			ri++;
			while(w>m){
				w-=a[ri]-a[li];
				li++;
				um--;
			}
			su=max(su,um);
	}
	printf("%lld",su);
	return 0;
}
