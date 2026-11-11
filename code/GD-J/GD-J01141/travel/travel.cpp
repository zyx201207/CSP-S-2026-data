#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << '1';
	}else{
		cout << '0';
	}
	if(a == c&&b[0] == d[0]&&d[1] == b[1]){
		cout << '1';
	}else{
		cout << '0';
	}
	if(a == c&&b[0] == d[0]&&d[1] == b[1]&&(((b[2] == 'A'||b[2] == 'B'||b[2] == 'C')&&(d[2] == 'A'||d[2] == 'B'||d[2] == 'C'))||((b[2] == 'D'||b[2] == 'F')&&(d[2] == 'D'||d[2] == 'F')))){
		cout << '1';
	}else{
		cout << '0';
	}
	if(a == c&&b[0] == d[0]&&d[1] == b[1]&&(((b[2] == 'A'||b[2] == 'B'||b[2] == 'C')&&(d[2] == 'A'||d[2] == 'B'||d[2] == 'C'))||((b[2] == 'D'||b[2] == 'F')&&(d[2] == 'D'||d[2] == 'F')))&&abs(int(d[2] - b[2])) == 1){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
	
	
}
