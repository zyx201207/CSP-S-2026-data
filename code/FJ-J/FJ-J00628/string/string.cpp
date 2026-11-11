#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// dfs n

struct Node{
	long long x;
	char r;
} s[1000005];

//char q[100000005];
long long idx = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n, ans = 0, sr = 0;
	cin >> n;
	
	for(long long i = 0; i < n; i ++ ){
		long long a;
		char c;
		cin >> a >> c;
		
		s[i].x = a, s[i].r = c;
		
		sr += a;
	}
	
	
	
//	for(int i = 0; i < n; i ++ ){
//		for(int j = 0; j < s[i].x; j ++ ){
//			q[idx ++ ] = s[i].r;
////			cout << s[i].r;
//		}
//	}
////	cout << endl << endl << endl;
//	
//	for(int i = 0; i < (idx + 1) / 2; i ++ ){
//		if(q[i] != q[idx - i - 1]) ans ++;
//	}
	
	
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	long long l = 0, r = n - 1;

	for(long long j = 0; j < (sr) / 2;){
		long long k = sr - j - 1;
		
		
		if(s[l].x < s[r].x){
			j += s[l].x;
			
			if(s[l].r != s[r].r){
				ans += s[l].x;
			}
			s[r].x -= s[l].x;
			l ++;
		}else if(s[l].x > s[r].x){
			j += s[r].x;
			
			if(s[r].r != s[l].r){
				ans += s[r].x;
			}
			s[l].x -= s[r].x;
			r --;
		}else{
			j += s[l].x;
			
			if(s[l].r != s[r].r){
				ans += s[l].x;
			}
			l ++, r --;
		}
	}
	
	cout << ans;
	
	return 0;
}
