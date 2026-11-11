#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[10];
	bool b = true;
	for(int i = 0;i < 10;i++){
		cin >> a[i];
	}
	if(a[0] == a[5]&&a[1] == a[6]){
		cout << 1;
		if(a[3] == a[8]&&a[2] == a[7]){
			cout << 1;
			if(a[4] == 'D'&&a[9] == 'F'){
				cout << 1;
			}else if((a[4] == 'A'||a[4] == 'B'||a[4] == 'C')&&(a[9] == 'A'||a[9] == 'B'||a[9] == 'C')){
				cout << 1;
			}else{
				cout << 0;
				b = false;
			}
		}else{
			cout << 0 << 0;
			b = false;
		}
	}else{
		cout << 0 << 0 << 0;
		b = false;
	}
	if((a[4] == 'D'&&a[9] == 'F')||(a[4] == 'F'&& a[9] == 'D')){
		if(b){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if((a[4] == 'A'&&a[9] == 'B')||(a[4] == 'C'&&a[9] == 'B')||(a[4] == 'B'||a[9] == 'A')||(a[4] == 'B'&&a[9] == 'C')){
		if(b&&!(a[4]=='A'&&a[9] == 'C')&&!(a[9]=='A'&&a[4] == 'C')){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	return 0;
}
