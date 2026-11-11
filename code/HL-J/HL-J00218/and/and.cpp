#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+100;
long long n,m;
long long a[N];
long long ma;
//x:the number  t:the start  num:the answer now
void dfs(long long x,long long t,long long num){
	long long i,k;
	if (x <= m && t > n) return;
	if (x > m){
		ma = max(ma,num);
		return;
	}
	for (i = t;i <= n;i++){
		if (x == 1) k = a[i];
		else k = num&a[i];
//		if (x+n-t < m) break;
		dfs(x+1,i+1,k);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,sum;
	scanf("%lld%lld",&n,&m);
	for (i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		if (i == 1) sum = a[i];
		sum &= a[i];
	}
	if (m == n){
		cout<<sum<<endl;
		return 0;
	}
	dfs(1,1,0);
	cout<<ma<<endl;
	return 0;
}