#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxa = 0;
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	if(m == 1){
		sort(a + 1,a + 1 + n);
		cout << a[n];
		return 0;
	}
	do{
		long long cnt = 0;
		for(int i = 1; i <= m; i++){
			if(i == 1){
				cnt = a[1];
			}else{
				cnt &= a[i];
			}
		}
		maxa = max(maxa,cnt);
	}while(next_permutation(a + 1,a + 1 + n));
	printf("%lld",maxa);
	return 0;
}
