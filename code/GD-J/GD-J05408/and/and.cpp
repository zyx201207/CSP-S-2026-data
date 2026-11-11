#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10 ;
long long n,m,a[N],maxx;
void dg(long long c,long long y,long long h) {
	for(long long i = c;i <= n;i++) {
		if(!(y >= m)) dg(i+1,y+1,h&a[i]) ;
		else if(h > maxx) {
			maxx = h ;
			return ;
		}else return ;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1;i <= n;i++) cin >> a[i] ;
	sort(a+1,a+1+n) ;
	dg(1,0,LLONG_MAX);
	cout << maxx ;
	return 0;
}
