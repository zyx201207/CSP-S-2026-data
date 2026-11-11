#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node{
	char c;
	long long x;
}a[N];
long long n, vis[N], ans;
node lastl, lastr;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>> n;
	for(int i = 1; i <= n; i ++){
		cin>> a[i].x>> a[i].c;
	}
	long long l = 1, r = n;
	while(l < r){
		if(lastl.x < 1 && lastr.x < 1){
			if(a[l].x == a[r].x){
				if(a[l].c != a[r].c){
					ans += a[l].x;
				}
				l ++, r --;
			}else if(a[l].x > a[r].x){
				lastl.x = a[l].x - a[r].x;
				lastl.c = a[l].c;
				if(a[l].c != a[r].c){
					ans += a[r].x;	
				}
				r --;
			}else{
				lastr.x = a[r].x - a[l].x;
				lastr.c = a[r].c;
				if(a[l].c != a[r].c){
					ans += a[l].x;	
				}
				l ++;
			}
		}else if(lastl.x >= 1 && lastr.x < 1){
			if(lastl.x == a[r].x){
				if(lastl.c != a[r].c){
					ans += a[r].x;
				}
				l ++, r --;
				lastl.x = 0;
			}else if(lastl.x > a[r].x){
				lastl.x = lastl.x - a[r].x;
				if(lastl.c != a[r].c){
					ans += a[r].x;	
				}
				r --;
			}else{
				lastr.x = a[r].x - lastl.x;
				lastr.c = a[r].c;
				if(lastl.c != a[r].c){
					ans += lastl.x;	
				}
				lastl.x = 0;
				l ++;
			}
		}else if(lastl.x < 1 && lastr.x >= 1){
			if(a[l].x == lastr.x){
				if(a[l].c != lastr.c){
					ans += a[l].x;
				}
				l ++, r --;
				lastr.x = 0;
			}else if(lastr.x > a[l].x){
				lastr.x = lastr.x - a[l].x;
				if(lastr.c != a[l].c){
					ans += a[l].x;	
				}
				l ++;
			}else{
				lastl.x = a[l].x - lastr.x;
				lastl.c = a[l].c;
				if(lastr.c != a[l].c){
					ans += lastr.x;	
				}
				lastr.x = 0;
				r --;
			}
		}
	}
	cout<< ans;
	return 0;
}
