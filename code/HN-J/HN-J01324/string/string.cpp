#include<bits/stdc++.h>
#include<algorithm>
#define LL long long
using namespace std;

struct apple{
	char ch;
	LL len;
	LL pn;
	LL end;
};
/*
2
2 a
4 c

aabbcc
012345

2
*/
const int N = 2e5+4;
LL n,l = 0;
apple a[N];
LL ans;

LL find(LL x){
	if(x >= a[n].pn) return n;
	LL l1 = 0,r1 = n+1;
	while(l1 < r1){
		LL mid1 = l1+((r1-l1+1)>>1);
		if(a[mid1].pn <= x){
			l1 = mid1;
		}else{
			r1 = mid1-1;
		}
	}
	return l1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].len >> a[i].ch;
		a[i].pn = l;
		l += a[i].len;
		a[i].end = l-1;
	}
	for(int i = 1;i <= n && a[i].pn < l>>1;i++){
		LL l1 = a[i].pn,r1;
		r1 = min(a[i].end,l>>1);
		LL l2 = l-r1-1,r2 = l-l1-1;
		LL pl = find(l2),pr = find(r2);
		if(pl != pr){
			if(a[pr].ch != a[i].ch){
				ans += r2-max(a[pr].pn,l2)+1;
			}
			if(a[pl].ch != a[i].ch){
				ans += min(a[pl].end,r2)-l2+1;
			}
			for(int j = pl+1;j < pr;j++){
				ans += a[j].len;
			}
		}else{
			if(a[pl].ch != a[i].ch){
				ans += r2-l2+1;
			}
		}	
	}
	cout << ans;
	return 0;
}
