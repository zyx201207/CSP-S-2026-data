#include <bits/stdc++.h>
using namespace std;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.ans","w",stdout);
int a,b;
string a1,b1;
cin >> a >> a1 >> b >> b1;
if(a == b){
	cout << 1;
}else{
	cout << 0 << 0 << 0 << 0;
	return 0;
}
if(a1[0] == b1[0] && a1[1] == b1[1]){
	cout << 1;
}else{
	cout << 0;
}
if(a1[0] == b1[0] && a1[1] == b1[1] && ((int(a1[2]) >= 'A' && int(b1[2]) <= 'C') || (int(a1[2]) == 'D' && int(b1[2]) == 'F'))){
	cout << 1;
}else{
	cout << 0;
}
if(a1[0] == b1[0] && a1[1] == b1[1] && ((int(a1[2]) >= 'A' && int(b1[2]) <= 'C') || (int(a1[2]) >= 'D' && int(b1[2]) <= 'F')) && (int(a1[2]) - int(b1[2]) == 1 || int(b1[2]) - int(a1[2]) == 1)){
	cout << 1 ;	
}else{
	cout << 0;
}
	return 0;
}
