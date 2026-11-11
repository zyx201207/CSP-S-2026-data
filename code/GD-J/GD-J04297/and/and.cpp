#include<bits/stdc++.h>
using namespace std;
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
#define int long long
const int N = 2e5 + 5;
int n , m;
//黄~绿，应该是黄
int a[N] , ans;
bitset<N> vis;//1表示不可取，0表示可取的数 
bool check(int it){
	int can = 0;
	for(int i = 1;i <= n;i ++){
		if((a[i] & it) != 0 && vis[i] == 0){
			can ++;
		}
	}
	if(can >= m){//能取的数超过m个 
		for(int i = 1;i <= n;i ++){
			if((a[i] & it) == 0){
				vis[i] = 1;//标记不可去 
			}
		}
		return 1;
	}else{
		return 0;
	}
} 
signed main(){
	File("and");
	scanf("%lld %lld" , &n , &m);
	for(int i = 1;i <= n;i ++){
		scanf("%lld" , a + i);
	}
	for(int i = 20;i >= 0;i --){
		if(check(1 << i)) ans += (1 << i);
	}
	printf("%lld\n" , ans);
	return 0;
}
//100
