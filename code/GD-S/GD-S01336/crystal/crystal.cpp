#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

struct crystal{ int num ; long long val ; } ;
crystal f[N] ;

int n , ans , cnt , final_num[N] , final_tot[N] ;
long long m , a[N]  , final_res[N] ;

bool check( int x , int tot , long long res )
{
	if( ( f[x+1].val - f[x].val ) * tot <= res && x < cnt )
	{
		return true ;
	}
	return false ;
}

int best_deal( int x )
{
	long long res = m ;
	int pos = x ;
	crystal now ;
	
	now.num = f[x].num ;//现在有几个数 
	now.val = f[x].val ;//现在数的值 
	
	while( check(pos,now.num,res) ) // 可以更上一层楼 
	{
		res -= ( f[pos+1].val - f[pos].val ) * now.num ;
		now.num += f[pos+1].num ;//加入新的一群 
		now.val = f[pos+1].val ; 
		pos ++ ;
	}	
	
	return now.num ;
} 
 
int main()
{
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	
	// 读入 ： 
	scanf("%d%lld",&n,&m) ;
	
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%lld",&a[i]) ;
	}
	
	
	// 排序 与 离散化 
	sort( a + 1 , a + n + 1 ) ;
	
	a[0] = -1e18 ;
	
	for(int i = 1 ; i <= n ; i++ )
	{
		if( a[i] != a[i-1] )
		{
			f[++cnt].num = 1 ;
			f[cnt].val = a[i] ;
		}
		else
		{
			f[cnt].num ++ ;
		}
	}
	
	// 计算 
	for(int i = 1 ; i < cnt ; i++ )
	{
		ans = max( ans , best_deal(i) ) ;
	} 

	// 输出 
	printf("%d",ans) ;

	return 0 ; 
} 
