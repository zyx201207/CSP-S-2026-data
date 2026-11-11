#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int z1,z2,c1,c2;
	cin >> z1 >> c1;
	char x=getchar();
	cin >> z2 >> c2;
	char y=getchar();
	if(z1==z2){
		cout << "1";
		if(c1==c2){
			cout << "1";
			if(x<='C'&&y<='C'||x>'C'&&y>'C'){
				cout << "1";
				if(abs(x-y)<2&&(!(x=='C'&&y=='D'||x=='D'&&y=='C'))){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
