#include <iostream>
#include <vector>
using namespace std;
long long maxn = -9999;
long long N,k;
const int MAXX = 2e5+5;
long long a[MAXX];
void dfs(int i,int n,int l){
	if (i==N)return;
	if (l == k){
		if (n > maxn){
			maxn = n;
		}
		return ;
	}
	
	if (l == 0){
		dfs(i,a[i],1);
		dfs(i+1,0,0);
	}else{
		dfs(i+1,n&a[i+1],l+1);
		dfs(i+1,n,l);
	}
	
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	scanf("%lld %lld",&N,&k);
	if (k == 1){
		for (long long i = 0;i<N;i++){
			scanf("%lld",&a[i]);
			if (a[i] > maxn)maxn=a[i];
		}
	}
	else if (N == k){
		for (long long i = 0;i<N;i++){
			scanf("%lld",&a[i]);
			if (maxn == -9999)maxn = a[i];
			else maxn = maxn&a[i];
		}
	}else{
		for (long long i = 0;i<N;i++){
			scanf("%lld",&a[i]);
		}
		dfs(0,0,0);
	}
	
	printf("%lld",maxn);
}
