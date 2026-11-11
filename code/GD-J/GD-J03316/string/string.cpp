#include <bits/stdc++.h>
using namespace std;
struct sstring{
	long long x;
	string y;
}b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s = "" , c;
	long long a , n , pos = 1 , l = 0 , r = 0 , ans = 0 , p1 = 1 , p2 , sum = 0 , sum1 = 0;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a >> c;
		if(b[pos].y == c || (pos == 1 && b[pos].x == 0)){
			b[pos].y = c;
			b[pos].x += a;
		}
		else{
			pos ++;
			b[pos].y = c;
			b[pos].x += a;
		}
		sum += a;
	}
	p2 = pos;
	while(p1 <= p2){
		if(l == 0){
			l = b[p1].x;
			sum1 += b[p1].x;
			p1 ++;
		}
		if(r == 0){
			r = b[p2].x;
			sum1 += b[p2].x;
			p2 --;
		}
		if(b[p1].y == b[p2].y){
			if(l <= r){
				l = 0;
				r -= l;
			}
			else{
				r = 0;
				l -= r;
			}
		}
		else if(b[p1].y != b[p2].y){
			if(l <= r){
				ans += l;
				l = 0;
				r -= l;
			}
			else{
				ans += r;
				r = 0;
				l -= r;
			}
		}
		if(p1 == p2){
			ans += l + r;
			if(b[1].x >= (sum+1) / 2){
				ans -= 1;
			}
			break;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
