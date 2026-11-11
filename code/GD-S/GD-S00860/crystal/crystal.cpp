#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[500005]  , maxn;
long long x , l , r , z;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	#include <bits/stdc++.h>

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i++){
		long long dis = 0;
		for(int j = 1;j <= n;j++){
			if(a[j] <= i){
				if(i - a[j] <= m){
					dis++;
				}
				else break;
			}
			maxn = max(maxn , dis);
		}
	}
	cout << maxn;
}

	return 0;
	
} 
