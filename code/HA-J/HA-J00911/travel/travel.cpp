#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[15];
	for(int i =1;i <= 13;i++){
		int b = getchar();
		a[i] = b;
	}
	if(a[1] != a[8] or a[2] != a[9]){
		cout << "0000";
	}
	if(a[1] == a[8] and a[2] == a[9]){
		if(a[4] != a[11] or a[5] != a[12]){
			cout << "1000";
		}
	}
	if(a[1] == a[8] and a[2] == a[9]){
		if(a[4] == a[11] and a[5] == a[12]){
			if(a[6] <= 67 and a[13] >= 68){
				cout << "1100";
			}
			if(a[6] >= 68 and a[13] <= 67){
				cout << "1100";
			}
	    }
	}
	if(a[1] == a[8] and a[2] == a[9]){
		if(a[4] == a[11] and a[5] == a[12]){
			if(a[6] <= 67 and a[13] <= 67){
				if(a[6] - a[13] == 1 or a[13] - a[6] == 1){
					cout << "1111";
				}
				else{
					cout << "1110";
				}
			}
			if(a[6] >= 68 and a[13] >= 68){
				cout << "1111";
			}
		}
	}
	
	return 0;
}
