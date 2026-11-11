#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool flag1,flag2,flag3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d; 
	if(a == c){
		cout << 1;
		flag1 = 1;
	}else cout << 0;
	if(flag1&&b[1] == d[1]&&b[0] == d[0]){
		cout << 1;
		flag2 = 1;
	}else cout << 0;
	if(b[2] == 'A'||b[2] == 'B'||b[2] == 'C'){
		if(flag2&&(d[2] == 'A'||d[2] == 'B'||d[2] == 'C')){
			flag3 = 1;
			cout << 1;
		}else cout << 0;
	}else{
		if(flag2&&(d[2] == 'D'||d[2] == 'E')){
			flag3 = 1;
			cout << 1;
		}else cout << 0;
	}if(flag3&&abs(b[2] - d[2]) == 1&&b[2] != 'C'&&d[2] != 'D')
		cout << 1;
	else cout << 0;
	return 0;
}
