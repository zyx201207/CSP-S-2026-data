#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long a;
	char s;
}t[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> t[i].a >> t[i].s;
	}
	
	int l = 1, r = n;
	long long ans = 0;
	while (l < r){
		if (t[l].s != t[r].s){
			if (t[l].a > t[r].a){
				ans += t[r].a;
				t[l].a -= t[r --].a;
			}else if (t[r].a > t[l].a){
				ans += t[l].a;
				t[r].a -= t[l ++].a;
			}else{
				ans += t[l].a;
				l ++, r --;
			}
		}else{
			if (t[l].a > t[r].a){
				t[l].a -= t[r --].a;
			}else if (t[r].a > t[l].a){
				t[r].a -= t[l ++].a;
			}else{
				l ++, r --;
			}
		}
	}
	cout << ans; 
	return 0;
}

