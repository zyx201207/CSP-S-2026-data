#include <iostream>
#include <cstdio>
using namespace std;
int c,t,n,c1[2000005],c2[2000005];
long long d,x[2000005] = {-0x7fffffffffffffff},ans; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for(;t--;){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i++)
			cin >> x[i];
		x[n+1] = 0x7fffffffffffffff;
		for(int i = 1,l = 1;i <= n;i++){
			while(x[i]-x[l] > d)
				l++;
			if(i == l || i < n && x[i+1]-x[l] <= d)
				continue;
			c1[i] = c1[l]+1;
		}
		for(int i = n,r = n;i;i--){
			while(x[r]-x[i] > d)
				r--;
			if(i == r || i > 1 && x[r]-x[i-1] <= d)
				continue;
			c2[i] = c2[r]+1;
		}
		for(int i = 2,l1 = 0,l2 = 0,r1 = 0,r2 = 0;i+2 <= n;i++){
			if(x[i]-x[i-1] > d || x[i+1]-x[i] > d || x[i+2]-x[i+1] > d)
				continue;
			r1 = max(r1,i+1);
			r2 = max(r2,i+1);
			while(x[l1] < x[i+1]-d)
				l1++;
			while(l2 < i && x[l2] < x[i+2]-d)
				l2++;
			while(x[r1] <= x[i-1]+d)
				r1++;
			while(x[r2] <= x[i]+d)
				r2++;
			r1--;
			r2--;
			if(l1 == i || r2 == i+1)
				continue;
			ans += 1ll*(l2-l1+(l1==l2?0:c1[l1]))*(r2-r1+(r1==r2?0:c2[r2]));
		}
		for(int i = 1;i <= n;i++)
			c1[i] = c2[i] = 0;
		cout << ans << '\n';
	}
	return 0;
}
/*
trick:x[i+1]-x[i],x[i+2]-x[i+1],x[i]-x[i-1]<=d
(i,i+1) -> 
x[i+1]-d<=x[l]<x[i+2]-d
x[i-1]+d<x[r]<=x[i]+d
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
