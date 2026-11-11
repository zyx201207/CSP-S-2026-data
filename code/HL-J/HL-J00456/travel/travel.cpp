#include <bits/stdc++.h>
using namespace std;
//85~100 
string cx1, cx2, zw1, zw2;
bool f1, f2, f3; 
int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    freopen("travel.in", "r", stdin); //记得解除！！ 
    freopen("travel.out", "w", stdout);
	//列不挨着行也不挨着 
 	cin >> cx1 >> zw1 >> cx2 >> zw2;
 	if(cx1 == cx2){
 		cout << "1";
 		f1 = 1;
	 }else{
	 	cout << "0";
	 	f1 = 0;
	 }
	 if(zw1[0] == zw2[0] && zw1[1] == zw2[1] && f1 == 1){
	 	cout << "1";
	 	f2 = 1;
	 }else{
	 	cout << "0";
	 	f2 = 0;
	 }
	 if(f1 == 1 && f2 == 1 && ( ((zw1[2]=='A' || zw1[2]=='B' || zw1[2]=='C') && (zw2[2]=='A' || zw2[2]=='B' || zw2[2]=='C')) || ((zw1[2]=='D' || zw1[2]=='F') && (zw2[2]=='D' || zw2[2]=='F')) ) ){
	 	cout << "1";
	 	f3 = 1;
	 }else{
	 	cout << "0";
	 	f3 = 0;
	 }
	 if(f1 == 1 && f2 == 1 && f3 == 1 && ( (zw1[2] == 'A' && zw2[2] == 'B') || (zw1[2] == 'B' && zw2[2] == 'A') || (zw1[2] == 'B' && zw2[2] == 'C') || (zw1[2] == 'C' && zw2[2] == 'B') || (zw1[2] == 'D' && zw2[2] == 'F') || (zw1[2] == 'F' && zw2[2] == 'D') ) ){
		cout << "1";	 	
	 }else{
	 	cout << "0";
	 }
	return 0; 
}
