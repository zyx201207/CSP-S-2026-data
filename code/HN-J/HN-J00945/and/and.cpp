#include<bits/stdc++.h>
using namespace std;
long long d[2][200005];
long long n,m;
long long and_(long long a,long long b){
	if(a==0)return b;
	return a&b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		long long a;
		scanf("%lld",&a);
		for(long long j=1;j<=i;j++){	
			d[0][j]=d[1][j];
			d[1][j]=max(d[0][j],and_(d[0][j-1],a));
		}
	}
	printf("%lld",d[1][m]);
	return 0;
}
