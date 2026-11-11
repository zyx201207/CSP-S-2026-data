#define MAXN 100002
#include <bits/stdc++.h>
using namespace std ;
int n ,m ;
int a[MAXN*5] ,ans[MAXN*3] ,head[MAXN*3] , next[MAXN*5] ,li[MAXN*3];
int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	scanf("%d%d",&n,&m) ;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d",&a[i]) ;
		next[head[a[i]]] = i ;
		head[a[i]] = i ;
	}
	for(int i = 1; i <= n ; i ++ ){
		int j = i ;
		while(j <= n){
			if(li[a[j]] != i ){
				ans[a[j]] ++ ;
				li[a[j]] = i ;
			}
			if(next[j]!=0) j = next[j] ;
			else j++ ;
		}
	}
	for(int i = 1 ; i <=m ;i ++ ) printf("%d ",ans[i]);
	return 0;
}

