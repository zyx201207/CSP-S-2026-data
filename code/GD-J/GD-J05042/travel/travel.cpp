#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","W","stdout");
   string a,b,c,d;
   cin >> a >> b >> c >> d;
   bool s = false;
if(a == c){
	cout << "1";

	if(b[0] == d[0] && b[1] == d[1]){
	cout << "1";
    }else{
	cout << "0";
    } 
    
if(b[0] == d[0] && b[1] == d[1]){
if(b[2] == 'A'&& d[2] =='B' ){
	cout << "1";
		s =true;
}else if(b[2] == 'A' && d[2] == 'C'){
	cout << "1";
		s =true;
}else if(b[2] == 'B' && d[2] == 'C'){
	cout << "1";
		s =true;
}else if(b[2] == 'B' && d[2] == 'A'){
	cout << "1";
		s =true;
}else if(b[2] == 'C' && d[2] == 'B'){
	cout << "1";
		s =true;
}else if(b[2] == 'C' && d[2] == 'A'){
	cout << "1";
		s =true;
}else if(b[2] == 'D' && d[2] == 'F'){
	cout << "1";
		s =true;
}else if(b[2] == 'F' && d[2] == 'D'){
	cout << "1";
	s =true;
}
}
if(s == true){
	s = false;
}else{
	cout << "0";
}

if(b[0] == d[0] && b[1] == d[1]){
	if(b[2] == 'B' && d[2] == 'C'){
	cout << "1";
		s =true;
}else if(b[2] == 'A' && d[2] == 'B'){
	cout << "1";
		s =true;
}else if(b[2] == 'B' && d[2] == 'A'){
	cout << "1";
		s =true;
}else if(b[2] == 'C' && d[2] == 'B'){
	cout << "1";
		s =true;
}else if(b[2] == 'D' && d[2] == 'F'){
	cout << "1";
		s =true;

}else if(b[2] == 'F' && d[2] == 'D'){
	cout << "1";
		s =true;
}

}
if( s == false){
	cout << "0";
}






}else{
	cout <<"0000";
}




	return 0;
}
