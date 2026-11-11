#include<bits/stdc++.h>
using namespace std;
long long n , m , a[200005] , ans = 0;
void dfs(int cnt , int sum , int x)
{
	//cout << "x:" << x << " sum:" << sum  << " cnt:" << cnt<< "\n";
	if(cnt == m)
	{
		//ans = max(ans , sum);
		//cout << ans << " " << sum << "\n";
		return ;
	}
	
	if(x == n + 1) return ;
	dfs(cnt++ , a[x] & sum , x + 1);
	dfs(cnt , sum , x + 1);
}
bool cmp(int x , int y)
{
	return x > y;
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
		dfs(1 , a[i] , i);
	sort(a + 1 , a + 1 + n , cmp);
	cout << a[m];
	return 0;
}
