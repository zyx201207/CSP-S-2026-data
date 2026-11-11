
#include <bits/stdc++.h>

using namespace std;

string x1, y1, x2, y2;
bool a[10];

int main(){
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2){	
		a[0] = true;
		if(y1[0] == y2[0] && y1[1] == y2[1]){
			a[1] = true;
			if((y1[2] == 'A' || y1[2] == 'B' || y1[2] == 'C') && (y2[2] == 'A' || y2[2] == 'B' || y2[2] == 'C') || (y1[2] == 'D' || y1[2] == 'F') && (y2[2] == 'D' || y2[2] == 'F')){
				a[2] = true;
				if( (y1[2] - y2[2] == 1 || y2[2] - y1[2] == 1) && (y1[2] == 'D' || y1[2] == 'F') && (y2[2] == 'D' || y2[2] == 'F')){
					a[3] = true;
				}else if((y1[2] - y2[2] == 1 || y2[2] - y1[2] == 1) && (y1[2] == 'A' || y1[2] == 'B' || y1[2] == 'C') && (y2[2] == 'A' || y2[2] == 'B' || y2[2] == 'C')){
					a[3] = true;
				}else{
					a[3] = false;
				}
			}else{
				a[2] = false;
				a[3] = false;
			}
		}else{
			a[1] = false;
		}
		
	}else{
		a[0] = false;
	}	
	
	
	for(int i = 0; i < 4; i++){
		if(a[i] == true){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}

/*

*/