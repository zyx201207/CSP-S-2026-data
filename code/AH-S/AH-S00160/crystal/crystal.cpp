#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5+10 ;

long long a[N] ;
long long n , m  ;

long long check(long long x){

   long long cnt = 1;
   long long sum = 0 ;

for(int i = x - 1; i >= 1 ; i --){
    if(sum + a[x] - a[i] > m)break ;

    sum+=a[x] - a[i] ;
    cnt++ ;
}

return cnt;

}

int main(){

  freopen("crystal.in" , "r" , stdin) ;
  freopen("crystal.out" , "w" , stdout) ;

  scanf("%d%d" , &n , &m) ;

  for(int i = 1 ; i <= n ;  i ++)scanf("%d" , &a[i]) ;

  sort(a+1 , a+n+1) ;

  long long maxn = -1;

  long long l = 1 , r = n ;

  while(l < r){

    int mid = (l + r + 1) >> 1 ;

    if(check(mid) > maxn){
            l = mid;
            maxn = check(mid) ;
       }
        else r = mid  - 1 ;
  }
  cout<<maxn<<endl;

  return 0 ;
}
