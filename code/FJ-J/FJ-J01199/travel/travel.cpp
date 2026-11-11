#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c1 >> c >> d >> c2;
	if(a!=c){
		cout << "0000";
	}else {
		cout << 1;
		if(b!=d) cout << "000";
		else {
			cout << 1;
			if('D'<=c1&&c1<='F'&&'D'<=c2&&c2<='F' || 'A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C'){
				cout << 1;
				if((int)c1-(int)c2==1||(int)c1-(int)c2==-1){
					cout << 1;
				}else {
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}
	}
	return 0;
}
