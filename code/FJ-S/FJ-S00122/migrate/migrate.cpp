#include <bits/stdc++.h>
using namespace std;

int c, t;
int n;
long long d, x[2000002];
int l[2000002], r[2000002], cnt[2000002];
long long f[2000002];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		int p = 1;
		for(int i=1;i<=n;i++){
			while(p <= n && x[p] - x[i] <= d) p++;
			p--;
			r[i] = p;
		}
		p = n;
		for(int i=n;i>=1;i--){
			while(p > 0 && x[i] - x[p] <= d) p--;
			p++;
			l[i] = p;
		}
		for(int i=1;i<=n;i++){
			cnt[i] = 0;
		}	
		for(int i=1;i<=n;i++){
			if(l[i] != i) cnt[l[i]]++;
		}
		for(int i=n;i>=1;i--){
			if(r[i] == i) {
				f[i] = 0;
				continue;
			}
			f[i] = cnt[r[i]-1] - (l[r[i]] == r[i]-1);
			int v = r[r[i]];
			if(l[v] == r[i]-1){
				bool flag = 1;
				for(int j=r[i];r[j]!=j;){
					int m = r[j];
					int v = r[m];
					f[i] += cnt[r[j]];
					if(l[v] != r[j]) break;
					j=m;
				}
			}
			else if(l[v] == r[i]){
				f[i] = f[i] + f[r[i]];
			}
		}
		long long Ans = 0;
		for(int i=1;i<=n;i++) Ans += f[i];
		printf("%lld\n",Ans);
	}
	
	return 0;
}

/*

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962


*/
