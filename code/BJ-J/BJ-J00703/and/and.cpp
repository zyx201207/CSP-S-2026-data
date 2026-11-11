#include<iostream>
#include<vector>
#include<cstdio>
using namespace std ;
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int n , m ;
	scanf("%d%d",&n,&m) ;
	vector<int> d[31] ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		scanf("%d",&x) ;
		for(int i = 0 ; i <= 30 ; i++){
			if(x&(1<<i))d[i].emplace_back(x) ;
		}
	}
	int i = 30 , ans = 0 ;
	while(i>=0){
		for(; i >= 0 ; i--){
			if(d[i].size()>=m) break ;
		}
		if(i == -1) break ;
		ans |= (1 << i) ;
		if(i) d[i-1] = {} ;
		for(int x : d[i]){
			if(i && x&(1<<(i-1)))d[i-1].emplace_back(x) ;
		}
		i-- ;
	}
	if(ans == 1 && d[0].size() < m) ans = 0 ;
	printf("%d\n",ans) ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}