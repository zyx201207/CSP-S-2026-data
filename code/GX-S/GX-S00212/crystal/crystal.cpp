#include <stdio.h>
#include <algorithm>
using namespace std;

long long int da[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long unsigned int m;
	int ans = 1;
	scanf("%d", &n);
	scanf("%llud", &m);
	//input and chafen0
	for(int i = 0; i < n; i++){
		scanf("%llud", &da[i]);
	}
	
	sort(da, da+n);
	for(int i = n-1; i >= 1; i--){
		da[i] = da[i] - da[i-1];
	}
	//meiju from back to forth
	for(int i = n-1; i >= 0; i--){
		long long unsigned int sc = 0, sum = 0;//single count, sum
		bool stopped = 0;
		for(int j = i; j >= 1; j--){
			sc += da[j], sum += sc;
			if(sum > m){
				if(ans < i-j+1) ans = i-j+1;
				stopped = 1;
				//printf("%i ", ans);
				break;
			}
		}
		if(!stopped && ans < i+1) ans = i+1;
	}
	
	printf("%i", ans);
	return 0;
}
