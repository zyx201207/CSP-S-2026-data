#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5+10;

long long n,m;
long long a[N]; 

//vector<int> yyw[32];

long long sl[N];
long long maimai(long long d){ //init d0 level ,sl cong 1 go 
	if(d == m){
		long long x = -1;
		for(long long i = 1; i <= m; i++){
			//printf("%d ",a[sl[i]]); 
			if(x == -1) x = a[sl[i]];
			else x &= a[sl[i]];
		}//printf("\n");
		return x;
	}
	long long asn = -1;
	for(long long i = sl[d]+1; i <= n-(m-d-1); i++){
		sl[d+1] = i;
		asn = max(asn,maimai(d+1));
	} 
	return asn;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
	scanf("%lld %lld",&n,&m);
	
	for(long long i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	
	printf("%lld",maimai(0));
	
	/*for(long long i = 1; i <= n; i++){
		long long x = a[i];
		for(long long j = 0; j < 32; j++){
			if(x == 0) break;
			if(x%2 == 1){
				yyw[j].push_back(i);
			}
			x /= 2;
		}
	}
	
	for(long long i = 0; i < 32; i++){
		printf("%lld yyw: ",i);
		for(long long j = 0; j < yyw[i].size(); j++){
			printf("%lld, ",a[yyw[i][j]]);
		}printf("\n");
	}*/
	
	return 0;
}
