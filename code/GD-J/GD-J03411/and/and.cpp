#include <bits/stdc++.h>
using namespace std;

long long n,m,A[1000006],pre;
bool cmp(long long aa,long long bb){
	return aa > bb;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
	}
	sort(A+1,A+n+1,cmp);
	pre=A[1];
	for(int i=2;i<=m;i++){
		pre=(pre&A[i]);
	}
	printf("%lld",pre);
	
	return 0;
} 
