#include<algorithm>
#include<cstdio>
using namespace std;
using uint = unsigned int;
constexpr int N = 2e5 + 5;
uint a[N], ans;
int n, m;
bool check(int x)noexcept{
	uint lim = ans | (1u << x);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if((a[i] & lim) == lim)cnt++;
		if(cnt == m)return 1;
	}
	return 0;
} 
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++)scanf("%u", a + i);
	for(int i = 30;i >= 0;i--){
		if(check(i))ans |= 1u << i; 
	}
	printf("%u", ans);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
