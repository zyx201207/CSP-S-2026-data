//会赢的，一定会
//这次我不会再输了
//Oct31==Dec25?
#include<bits/stdc++.h>
#define N 500010
using namespace std;
typedef long long LL;
//十年 OI 一场空，不开 long long 见祖宗
//这句话终于还是有用了吗。 
int n , ans = 1 , cnt;
LL m , a[N] , sum;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	scanf("%d%lld" , &n , &m);
	for(int i = 1 ; i <= n ; ++i)
		scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	//for(int i = 1 ; i <= cnt ; ++i)
	//	printf("%d %d\n" , a[i] , mp[a[i]]);
	//不是这个老牧师 C++98 为啥不让我用 auto 啊/fn/fn/fn
	//for(auto i : mp)
	//	a[++cnt] = i.first;
	int j = 1;
	for(int i = 1 ; i <= n ; ++i){
		sum += a[i];
		int l = i - j + 1;
		//printf("i:%d j:%d l:%d sum:%d\n" , i , j , l , sum);
		if(sum + m < a[i] * l){
			sum -= a[j];
			j += 1;
		}
		else
			ans = max(ans , l);
	}
	printf("%d" , ans);
	//我说这真比去年简单吧。 
	//欸我怎么写了 50min 
	return 0;
}
