#include <bits/stdc++.h>
using namespace std;
struct node{
	long long s;
	char b;
}a[1000005];
long long ans,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].s >> a[i].b;
	}
	int l = 1;
	int r = n;
	while(l < r){
		if (a[l].b == a[r].b){
			if (a[l].s > a[r].s) a[l].s -= a[r].s,r--;
			else if (a[l].s < a[r].s) a[r].s -= a[l].s,l++;
			else l++,r--;
		}else{
			if (a[l].s > a[r].s) a[l].s -= a[r].s,ans += a[r].s,r--;
			else if (a[l].s < a[r].s) a[r].s -= a[l].s,ans += a[l].s,l++;
			else ans += a[l].s,l++,r--;
		}
	}
	cout << ans;
	return 0;
}
