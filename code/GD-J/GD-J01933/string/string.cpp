#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],i,n,cs,le,ri;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	le=0,ri=n-1;
	while(le<=n>>1&&ri>=n>>1){
		int mi=min(a[le],a[ri]);
		if(c[le]==c[ri]){
			a[le]-=mi;
			a[ri]-=mi;
			if(a[le]==0) le++;
			else ri--;
		}
		else{
			a[le]-=mi;
			a[ri]-=mi;
			cs+=mi;
			if(a[le]==0) le++;
			else ri--;
		}
	}
	printf("%lld",cs);
	return 0;
}
