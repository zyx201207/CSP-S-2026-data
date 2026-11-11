#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
ll n , m , a[N] , s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	int l = 1 , r = 1;
	int now_ans = 0;
	int now_num = 0;
	for(;l <= n && r <= n;){ 
		int l1 = l + 1;
		if(l1 > n) break;
		int now_nump = now_num + (a[l1] - a[l]) * (l - r + 1);
//		cout << l << " " << l1 << " " << r << " " << now_nump << " " << now_num << endl;
		if(now_nump <= m){
			l = l1;
			now_num = now_nump;
			now_ans = max(now_ans , (l1 - r + 1));
		}
		else{
			int r1 = r + 1;
			now_num -= (a[l] - a[r]);
			r = r1;
		}
	}
	cout << now_ans;
}
