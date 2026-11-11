#include <iostream>
#include <string>
using namespace std;

const int maxn = 2e5+7;

int a[maxn];
bool ok[maxn];

inline bool getbit(int a , int d){ return (a>>d)&1; } 

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n , m , ans = 0;
	cin >> n >> m;
	
	for (int i = 0 ; i < n ; ++ i){
		cin >> a[i];
	}
	for (int i = 0 ; i < maxn ; ++ i){
		ok[i] = true;
	}
	
	for (int i = 29 ; i >= 0 ; -- i){
		ans <<= 1;
		int cnt = 0;
		
		for (int j = 0 ; j < n ; ++ j){
			if (ok[j] == false)
				continue;
			if (getbit(a[j],i))
				++ cnt;
		}
		
		if (cnt < m){
			continue;
		}
		
		for (int j = 0 ; j < n ; ++ j){
			if (ok[j] == false)
				continue;
			if (!getbit(a[j],i))
				ok[j] = false;
		}
		ans ++;
	}
	
	cout << ans;
	
	return 0;
}
