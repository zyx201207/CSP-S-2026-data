#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,m;

long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long x=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		x=(x & a[i]);
	}
	printf("%lld",x);
	return 0;
}