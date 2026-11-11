#include<bits/stdc++.h>
using namespace std;
struct F{
	int a;
	char c;
};
F a[200005], b[200005];
long long n, t, tt, ans, x, j = 1, i;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].c;
		t += a[i].a;
	}
	if (t % 2 == 0) t /= 2;
	else t /= 2, t++;
	for(i = 1; i <= n; i++){
		if (t >= a[i].a){
			b[i].a = a[i].a;
			b[i].c = a[i].c;
			t -= a[i].a;
			if (t == 0){
				t = i + 1;
				break;
			}
		}
		else if (t > 0){
			b[i].a = t;
			b[i].c = a[i].c;
			a[i].a -= t;
			t = i;
			break;
		}
	}
	for(i = n; i >= t; ){
		if (a[i].a == 0) i--;
		if (b[j].a == 0) j++;
		if (a[i].c == b[j].c){
			x = min(a[i].a, b[j].a);
			a[i].a -= x;
			b[j].a -= x;
			if (a[i].a == 0) i--;
			if (b[j].a == 0) j++;
		}
		else{
			if (a[i].a <= b[j].a){
				a[i].c = b[j].c;
				x = a[i].a;
				a[i].a = 0;
				b[j].a -= x;
				ans += x;
				if (a[i].a == 0) i--;
				if (b[j].a == 0) j++;	
			}
			else{
				x = b[j].a;
				b[j].a = 0;
				a[i].a -= x;
				ans	+= x;
				if (a[i].a == 0) i--;
				if (b[j].a == 0) j++;
			}
		}
	}
	cout << ans;
	return 0;
}
