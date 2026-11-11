#include <cstdio>
#include <algorithm>
#define N 500005
#define ll long long
using namespace std;

int n, i, j, l, r, md;
ll m, a[N], s, t;
void RP(){
	#define inf 1000000000000000000
	ll rp = inf;
	rp++;
}
int main(){
	RP();
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(i=1; i<=n; i++)	scanf("%lld", a+i);
	sort(a+1, a+1+n);
	for(i=1; i<=n; i++)	a[i] += a[i-1];
	l = 1, r = n;
	while(l < r){
		md = l+r+1 >> 1;
		for(i=1; i+md-1<=n; i++){
			j = i+md-1;
			s = a[j]-a[i-1];
			t = (a[j]-a[j-1])*md;
			if(t-s <= m)	break;
		}
		if(t-s <= m)	l = md;
		else	r = md-1;
	}
	printf("%d", l);
	return 0;
}
