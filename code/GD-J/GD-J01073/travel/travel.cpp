#include <bits/stdc++.h>
using namespace std;
long long nx,ny;
string ax,ay,bx,by;
bool check_one(string x,string y,long long n){
	for(long long i = 1;i <= n;i++){
		if(x[i] != y[i]){
			return false;
		}
	}
	return true;
}
bool check_two(char x,char y){
	if((x == 'A' && y == 'B') || (x == 'A' && y == 'C') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'C' && y == 'A') || (x == 'B' && y == 'A') || (x == 'D' && y == 'F') || (x == 'F' && x == 'D')){
		return true;
	}
	return false;
}
bool check_three(char x,char y){
	if((x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'C' && y == 'B') || (x == 'B' && y == 'A') || (x == 'D' && y == 'F') || (x == 'F' && x == 'D')){
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin >> ax >> ay >> bx >> by;
	nx = ax.size(),ny = ay.size();
	ax = " " + ax,ay = " " + ay;
	bx = " " + bx,by = " " + by;
	if(check_one(ax,bx,nx)){
		cout << 1;
		if(check_one(ay,by,ny - 1)){
			cout << 1;
			if(check_two(ay[ny],by[ny])){
				cout << 1;	
				if(check_three(ay[ny],by[ny])){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
