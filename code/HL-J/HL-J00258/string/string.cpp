#include<bits/stdc++.h>
using namespace std;
int nn ;
string s ;
long long ans ;
struct N{
	int cnt ;
	char c ;
}n[200005];
int f1[200005] , f2[200005];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin.tie(0);
	cin >> nn;
	for(int i = 1 ; i <= nn ; i++){
		cin >> n[i].cnt >> n[i].c;
	}
	int l = 0 , r = nn + 1 ;
	N ln , rn ;
	ln.cnt = 0 ;
	rn.cnt = 0 ;
	
	while(f1[l] != 1 && f2[r] != 1 && r >= 1 && l <= nn){
		if(ln.c == rn.c){
			if(ln.cnt >= rn.cnt){
				ln.cnt -= rn.cnt;
				rn.cnt = 0;
			}else{
				rn.cnt -= ln.cnt;
				ln.cnt = 0 ;
			}
		}else{
			if(ln.cnt >= rn.cnt){
				ans += rn.cnt;
				ln.cnt -= rn.cnt;
				rn.cnt = 0;
			}else{
				ans += ln.cnt;
				rn.cnt -= ln.cnt;
				ln.cnt = 0 ;
			}
		}
		if(ln.cnt == 0){
			l++;
			f2[l] = 1 ;
			ln.cnt = n[l].cnt;
			ln.c = n[l].c;
		}
		if(rn.cnt == 0){
			r--;
			f1[r] = 1 ;
			rn.cnt = n[r].cnt;
			rn.c = n[r].c;
		}
	}
	cout << ans ;
	return 0 ;
}


