#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e5+10;
struct Node{
	int s;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i].s >> a[i].c;
		sum += a[i].s;
	}
	int ans = 0;
	int li = 1,ri = n;
	for (;li < ri;){
		if(a[li].c != a[ri].c){
			if(a[li].s < a[ri].s){
				ans += a[li].s;
				a[ri].s -= a[li].s;
				li++;
			}
			else if(a[li].s == a[ri].s){
				ans += a[li].s;
				li++;
				ri--;
			}
			else {
				a[li].s -= a[ri].s;
				ans += a[ri].s;
				ri--;
				
			}
		}
		else{
			if(a[li].s < a[ri].s){
				a[ri].s -= a[li].s;
				li++;
			}
			else if(a[li].s == a[ri].s){
				li++;
				ri--;
			}
			else {
				a[li].s -= a[ri].s;
				ri--;
			}
		}
	}
	cout << ans;
	return 0; 
}
