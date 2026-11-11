#include<bits/stdc++.h>
using namespace std;

const long long N = 5e5+10;

long long n,nn;
long long x[N],rx[N];
char c[N],rc[N];
long long e[N],re[N];
long long ans;

long long in_x;
char in_c;

long long ix[N];
long long qx[N];
char qc[N],qrc[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	
	scanf("%lld",&n);
	
	for(long long i = 1; i <= n; i++){
		scanf("%lld %c",&in_x,&in_c);
		x[i] = in_x;
		rx[n-i+1] = in_x;
		c[i] = in_c;
		rc[n-i+1] = in_c; 
	}
	
	for(long long i = 1; i <= n; i++){
		e[i] = e[i-1] + x[i];
		//printf("%lld ",e[i]);// debug
	
	}
	//printf("\n");// debug
	
	for(long long i = 1; i <= n; i++){
		re[i] = re[i-1] + rx[i];
		//printf("%lld ",re[i]);// debug
	}
	//printf("\n");// debug
	
	long long p1 = 1, p2 = 1, bf = -2778, vl;
	
	while(p1 <= n || p2 <= n){
		if((e[p1] <= re[p2] || p2 > n) && (p1 <= n)){
			// select e
			vl = e[p1++];
			if(vl != bf){
				ix[++nn] = vl;
				bf = vl;
			}
		}else{
			// select re
			vl = re[p2++];
			if(vl != bf){
				ix[++nn] = vl;
				bf = vl;
			}
		}
	}
	
	long long dp1 = 1, dp2 = 1;
	
	for(long long i = 1; i <= nn; i++){
		qx[i] = ix[i] - ix[i-1];
		if(ix[i] > e[dp1]) dp1++;
		if(ix[i] > re[dp2]) dp2++;
		qc[i] = c[dp1];
		qrc[i] = rc[dp2];
		//printf("[%c,%c]",qc[i],qrc[i]);
	}
	
	/*
	// debug
	for(long long i = 1; i <= nn; i++){
		printf("%c ",qc[i]);
	}
	printf("\n");
	for(long long i = 1; i <= nn; i++){
		printf("%c ",qrc[i]);
	}
	printf("\n"); 
	// ---*/

	for(long long i = 1; i <= nn; i++){
		if(qc[i] != qrc[i]){
			ans += qx[i];
		}
	}
	
	printf("%lld",ans/2);
	
	return 0;
}
