#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string cr, sr, cx, sx;
	cin >> cr >> sr >> cx >> sx;
	bool ans[6];
	if(cr == cx){
		ans[0] = 1;
		string r = "", x = "";
		for(int i = 0;i < sr.length()-1;i++){
			r += sr[i];
		}
		for(int i = 0;i < sx.length()-1;i++){
			x += sx[i];
		}
		if(r == x){
			ans[1] = 1;
			char rs, xs;
			rs = sr[sr.length()-1];
			xs = sx[sx.length()-1];
			if((rs <='C'&&xs <='C')||(rs>'C'&&xs>'C')){
				ans[2] = 1;
				if(rs > 'C'){
					ans[3] = 1;
				}else{
					if(fabs(int(rs) - int(xs)) == 1){
						ans[3] = 1;
					}else{
						ans[3] = 0;
					}
				}
			}else{
				ans[2] = 0;
				ans[3] = 0;
			}
		}else{
			ans[1] = 0;
			ans[2] = 0;
			ans[3] = 0;
		}
	}else{
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 0;
		ans[3] = 0;
	}
	for(int i = 0;i < 4;i++){
		cout << ans[i];
	}
	return 0;
}
