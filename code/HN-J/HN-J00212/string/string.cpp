#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5 + 5;
struct P{
	int sum;
	char ch;
}p[N];
int n, l = 1, r;
ll ans, cz;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	r = n;
	for(int i = 1; i <= n; i++) cin >> p[i].sum >> p[i].ch;
	while(l < r){
		cz = p[l].sum - p[r].sum;
	    if(p[l].ch != p[r].ch) ans += min(p[l].sum, p[r].sum);
		if(cz > 0){
			r--;
			p[l].sum = cz;
		}else if(cz < 0){
			l++;
			p[r].sum = -cz;
		}else{
			r--;
			l++;
		}
    }
	cout << ans;
	return 0;
} 
