#include<bits/stdc++.h>
using namespace std;
typedef long long llong; 

const int N = 5e5+10;

int n;
llong m,a[N];

/*                                                           

Wang YuanMing don't kill me!
It's too hard for me to solve the CSP-S so I was boring that I made this:

      ====     ===   ===   ===    ===    ===       ======    
     ======    ===  ====  ===    ====   ====     ===   ===   
    === ===    === ===== ===    === ===== ===   ===          
   =========    ====   ====    ===  ====  ===   ===   ===    
  ===    ===    ===    ===    ===   ===   ===    =======     
                                                           */

bool sl[N];
llong sls[N];

int maimai(int d, int s){ // d = 0+, s is max
	//printf("maimai d:%d\n",d); 
	if(d >= s){
		int nn = 0;
		for(int i = 1; i <= s; i++){
			if(sl[i]) sls[++nn] = a[i];
		}
		llong mx = *max_element(sls+1,sls+1+nn);
		llong cs = 0;
		for(int i = 1; i <= nn; i++){
			cs += mx - sls[i];
			if(cs <= m) return nn;
		}
		return 1;
	}
	int mx = 1;
	for(int i = 0; i <= 1; i++){
		sl[d+1] = (bool)i;
		mx = max(maimai(d+1,s),mx);
	}
	return mx;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d %lld",&n,&m); 
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	
	printf("%d",maimai(0,n));
	
	return 0;
}
