#include<iostream>
#include<cstdio>
using namespace std ;
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	int n ;
	scanf("%d",&n) ;
	string s ;
	while(n--){
		int x ;
		char c ;
		scanf("%d %c",&x,&c) ;
		while(x--) s += c ;
	}
	int l = s.size() >> 1, ans = 0 ;
	n = s.size() ;
	for(int i = 0 ; i < l ; i++){
		ans += (s[i]!=s[n-i-1]) ;
	}
	printf("%d\n",ans) ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}