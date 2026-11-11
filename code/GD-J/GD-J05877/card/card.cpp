
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int n, m;
ll arr[200005];
ll dp[200005]; 
//ll ans = 0x7fffffffffffffff;

//string to(long long x){
//	string str;
//	long long t = x;
//	while (t > 0){
//		char c = char(t % 2 + int('0'));
//		t /= 2;
//		str = c + str;
//	}
//	return str;
//}
//
//long long ad(string s1, string s2){
//	string as;
//	long long q;
//	int x;
//	if (s1.length() < s2.length()){
//		x = s2.length();
//		for (int i = 1;i <= s2.length() - s1.length();i++){
//			s1 = '0' + s1;
//		}
//	}
//	else {
//		x = s1.length();
//		for (int i = 1;i <= s1.length() - s2.length();i++){
//			s2 = '0' + s2;
//		}
//	}
//	for (int i = 0;i < x;i++){
//		if (s1[i] == 1 && s2[i] == 1)    as = as +'1';
//		else as = as + '0';
//	}
//	int l;
//	for (int i = 0;i < x;i++){
//		if (as[i] != '0')  l = i;
//	}
//	for (int i = l;i < x;i++){
//		q += pow(2, as.length() - l - 1) * int(as[i] - '0');
//	}
//	return q;
//}

int main (){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)    cin >> arr[i];
	for (int i = 1;i <= m;i++)    cout  << 0 << " ";
	return 0;
}

//4 2
//3 15 12 12

//#include <iostream>
//#include <cmath>
//#define ll long long
//using namespace std;
//
//int n, m;
//ll arr[200005];
//ll dp[2005][2005]; 
////ll ans = 0x7fffffffffffffff;
//
//int main (){
//	freopen("and3.in", "r", stdin);
//	freopen("and.txt", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)    cin >> arr[i];
//	for (int i = 1;i <= n;i++)dp[i][0] = 0x7fffffffffffffff;
////	dp[1] = arr[1];
//	for (int i = 1;i <= n;i++){
////		dp[1] = arr[i];
//		for (int j = 1;j <= i;j++){
//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & arr[i]);
//		}
//	}
//	cout << dp[n][m];
//	return 0;
//}

//4 2
//3 15 12 12

