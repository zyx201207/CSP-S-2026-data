#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200005;
int n;
struct stu{
	int x;
	char c; 
}a[maxn];
ll cnt = 0;
ll l, r;
ll len_l, len_r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].c;
	}
	l = 1, r = n;
	len_l = a[1].x;
	len_r = a[n].x;
	while(l < r){
		ll xx = min(len_l, len_r);
		if(a[l].c != a[r].c){
			cnt += xx;
		}
		len_l -= xx;
		len_r -= xx;
		if(len_l == 0){
			l++;
			len_l = a[l].x;
		}
		if(len_r == 0){
			r--;
			len_r = a[r].x;
		}
	}
	cout << cnt;
	return 0;
}
