#include<bits/stdc++.h>
using namespace std;
int n ;
long long m, ans=-1, maxx, j;
long long a[500005], v[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >>n >>m;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		v[i]=(i-1)*(a[i]-a[i-1])+v[i-1];
	}
	for( int i=1; i<=n; i++){
		j=i;
		while(v[j]-v[i]<=m){
			maxx++;
			j++;
			if(j>n) break;
		}
		if(ans<maxx) ans=maxx;
		maxx=0;
	}
	
	printf("%lld", ans);
	return 0;
} 

