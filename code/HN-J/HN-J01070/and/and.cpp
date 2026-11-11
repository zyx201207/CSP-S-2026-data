#define MAXN 200005
#include <bits/stdc++.h>
using namespace std ;//qwq kale
int n,m,ans;
int a[MAXN] ;
bool vis[MAXN] ;
//void kards(int a){
//	
//}
int main(){
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	cin >> n >>m ;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&a[i]) ;
	}
	for(int j= 29 ; j >=0 ; j --){
		int oc=0, tc=0 ;
		for(int i = 1 ; i <= n ; i ++ ) {
			if(vis[i] == 1)continue ;
			if(a[i]>>j)oc ++ ;
			else tc ++ ;
		}
		if(oc > m ){
			ans |=1<<j ;
			for(int i = 1 ; i <= n ; i ++ ){
				if(vis[i] == 1)continue ;
				else if((a[i]>>j)==0)vis[i] = 1 ; 
			}
		}if(oc == m){
			for(int i = 1 ; i <= n ; i ++){
				if(vis[i] == 1)continue ;
				if(a[i]>>j) ans&=a[i] ;
				printf("%d",ans) ;
				return 0 ;
			}
		}
	}
	printf("%d",ans) ;
	return 0;
}
