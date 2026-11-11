#include<bits/stdc++.h>
using namespace std;

const int N=2e6+7;
int c, t;
int n;
long long d;
long long x[N];
int up[N];
int down[N];
long long lf[N];
long long rt[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		for(int i=1;i<=n;i++){
			scanf("%lld", x+i);
		}
		for(int i=1;i<=n;i++){
			int l=i, r=n;
			int mid = (l+r)/2;
			while(l<r){
				if(x[mid]-x[i]<d){
					l = mid+1;
				}else{
					r = mid;
				}
				mid = (l+r)/2;
			}
			up[i] = l;
		}
		for(int i=n;i>=1;i--){
			int l=1, r=i;
			int mid = (l+r)/2;
			while(l<r){
				if(x[i]-x[mid]<=d){
					r = mid;
				}else{
					l = mid+1;
				}
				mid = (l+r)/2;
			}
			down[i] = l;
		}
		for(int i=1;i<=n;i++){
			lf[i] = 1;
			rt[i] = 1;
		}
		for(int i=1;i<=n;i++){
			lf[up[i]]+=lf[i];
		}
		for(int i=n;i>=1;i--){
			rt[down[i]]+=rt[i];
		}
		long long ans = 0;
		for(int i=1;i<=n;i++){
			if(up[i]!=i && down[up[i]]){
				if(up[up[i]-1]!=up[i]&&down[up[up[i]-1]] == up[i]-1){
					ans+=1LL*lf[i]*rt[up[up[i]-1]];
				}
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
