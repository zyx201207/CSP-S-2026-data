#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010];
stack<long long>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[a[i]]=i;
	}
	for(long long i=1;i<=m;i++)printf("%lld ",b[i]);
	return 0;
}
/*
4 3
1 2 1 3
*/
