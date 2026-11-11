#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node{
	long long l,r;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long len = 0;
	for(int i = 1;i <= n;i++){
		int x;
		char y;
		cin >> x >> y;
		a[i].l = len+1;
		a[i].r = len+x;
		a[i].c = y;
		len += x;
	}
	long long mid = len/2;
	long long p = 0,ans = 0;
	int ll = 1,rr = n;
	while(p < mid){
		long long l1 = a[ll].l,r1 = a[ll].r,l2 = a[rr].l,r2 = a[rr].r;
		long long l3 = len-r2+1,r3 = len-l2+1;
		//cout << l1 << ' ' << r1 << ' ' << l3 << ' ' << r3 << ' ' << endl;
		long long last = max(l1,l3);
		if(a[ll].c == a[rr].c){
		}else{
			ans += min(r1,r3)-last+1;
		}
		if(r1 == r3){
			ll++;
			rr--;
			p = r1;
		}
		else if(r1 < r3){
			ll++;
			p = r1;
		}else{
			rr--;
			p = r3;
		}
	}
	cout << ans;
	return 0;
}
