#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 1;
const int inf = 0x3f3f3f3f;
struct abc{
	int Size;
	char c;
};
abc a[N];
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		int sum;
		char c;
		cin >> sum >> c;
		a[i].Size = sum;
		a[i].c = c;
	}
	int l = 1;
	int r = n;
	int ans = 0;
	while(l <= r){
		if(a[l].c != a[r].c){
			if(a[l].Size < a[r].Size){
				ans += a[l].Size;
				a[r].Size -= a[l].Size;
				l ++;
			}else if(a[l].Size > a[r].Size){
				ans += a[r].Size;
				a[l].Size -= a[r].Size;
				r --;
			}else{
				ans += a[l].Size;
				l ++;
				r --;
			}
		}else{
			if(a[l].Size < a[r].Size){
				a[r].Size -= a[l].Size;
				l ++;
			}else if(a[l].Size > a[r].Size){
				a[l].Size -= a[r].Size;
				r --;
			}else{
				l ++;
				r --;
			}
		}		
	}
	cout << ans;
	return 0;
} 
