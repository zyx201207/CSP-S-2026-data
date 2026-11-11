# include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
string x , y , p , q;
bool flag = 1;
void solve()
{
	cin >> x >> y >> p >> q;
	flag &= x == p , cout << flag;
	string s = y.substr(0 , 2) , t = q.substr(0 , 2);
	flag &= (s == t) , cout << flag;
	s = y.substr(2 , 1) , t = q.substr(2 , 1);
	int m = s[0] - 'A' , n = t[0] - 'A';
	flag &= (m < 3 && n < 3) || (m >= 3 && n >= 3) , cout << flag;
	flag &= (m - 1 == n) || (n - 1 == m) || (m == 3 && n == 5) || (m == 5 && n == 3) , cout << flag;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in" , "r" , stdin); 
	freopen("travel.out" , "w" , stdout);
	int t = 1;
	while(t --) solve();
	return 0;
}
