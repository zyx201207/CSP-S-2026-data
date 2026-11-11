#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn = -1,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	if(m == 1){
		cout << a[n];
		return 0;
	}
	else if(m == n - 1){
		for(int i = 1;i <= n;i++){
			long long use = a[1];
			if(i == 1) use = a[2];
			for(int j = 1;j <= n;j++){
				if(j != i){
					use *= a[i];
				}
			}
			maxn = max(maxn,use);
		}
		cout << maxn;
	}
	else if(m == 2){
		for(long long i = 1;i < n;i++){
			for(long long j = i + 1;j <= n;j++){
				maxn = max(i & j,maxn);
			}
		}
		cout << maxn;
	}
	else{
		int use = a[1];
		for(int i = 2;i <= n;i++){
			use &= a[i];
		}
		cout << use;
	}
	return 0;
} 
