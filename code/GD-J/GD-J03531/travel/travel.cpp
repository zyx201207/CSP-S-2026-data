#include<bits/stdc++.h>
using namespace std;
int cr, cx, ans[10], pr, px;
char sr[10], sx[10];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%s%d%s" ,&cr ,sr + 1 ,&cx ,sx + 1);
	pr = sr[1] * 10 + sr[2];
	px = sx[1] * 10 + sx[2];
	if(cr == cx){
		ans[1] = 1;
		if(pr == px){
			ans[2] = 1;
			if((sr[3] < 'D' && sx[3] < 'D') || (sr[3] > 'C' && sx[3] > 'C')){
				ans[3] = 1;
				if(abs(sr[3] - sx[3]) <= 1 || (sr[3] == 'D' && sx[3] == 'F') || (sr[3] == 'F' && sx[3] == 'D'))
					ans[4] = 1;
			}
		}
	}
	printf("%d%d%d%d" ,ans[1] ,ans[2] ,ans[3] ,ans[4]);
	return 0;
}
