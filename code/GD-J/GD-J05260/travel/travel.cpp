#include <iostream>
using namespace std;
char ss1 , ss2;
int c1 , c2;
int s1 , s2;
bool check1(){
	if(ss1 == 'A') return (ss2 == 'B' || ss2 == 'C');
	if(ss1 == 'B') return (ss2 == 'A' || ss2 == 'C');
	if(ss1 == 'C') return (ss2 == 'A' || ss2 == 'B');
	if(ss1 == 'D') return ss2 == 'F';
	if(ss1 == 'F') return ss2 == 'D';
}
bool check2(){
	if(ss1 == 'A') return ss2 == 'B';
	if(ss1 == 'B') return (ss2 == 'A' || ss2 == 'C');
	if(ss1 == 'C') return ss2 == 'B';
	if(ss1 == 'D') return ss2 == 'F';
	if(ss1 == 'F') return ss2 == 'D';
}
void maincheck(){
	if(c1 != c2){
		cout << "0000"; return;
	}
	else cout << 1;
	if(s1 != s2){
		cout << "000"; return;
	}
	else cout << 1;
	if(!check1()){
		cout << "00"; return;
	}
	else cout << 1;
	if(check2()) cout << 1;
	else cout << 0;
}
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> c1 >> s1;
	ss1 = getchar();
	cin >> c2 >> s2;
	ss2 = getchar();
	maincheck();
	return 0;
} 
