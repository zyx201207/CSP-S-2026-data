#include <bits/stdc++.h>
using namespace std;

int a, c;
string b, d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int x=(b[0]-'0')*10+(b[1]-'0');
	int y=(d[0]-'0')*10+(d[1]-'0');
	int m=b[2]-64;
	int n=d[2]-64;
	if (a==c){
		cout << 1;
		if (x==y){
			cout << 1;
			if ((m<=3&&n<=3)||(m>=4&&n>=4)){
				cout << 1;
				if (abs(m-n)==1||(m==4&&n==6)){
					cout << 1;
				}else{
					cout << 0;
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
