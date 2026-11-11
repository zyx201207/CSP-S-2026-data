#include<iostream>
using namespace std;
bool is_s(char c1, char c2){//位于同一侧 
	if(((c1=='A')||(c1=='B')||(c1=='C'))&&((c2=='D')||(c2=='F')))
	return false;
	if(((c2=='A')||(c2=='B')||(c2=='C'))&&((c1=='D')||(c1=='F')))
	return false;
	return true;
}
bool pai(string a, string b){
	if(a[0]==b[0] && a[1]==b[1])
	return 1;
	return 0;
}
bool is_xiangl(char c1, char c2){
	if( ((c1=='A')&&(c2=='B')) || ((c1=='B')&&(c2=='C')) ||
	((c1=='B')&&(c2=='A')) || (c1=='C')&&(c2=='B'))
	return 1;
	if(((c1=='D')&&(c2=='F')) || ((c1=='F')&&(c2=='D')))
	return 1;
	return 0;
} 
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//车厢号，座位号
	int r1, x1;
	string r2, x2;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1==x1){
		cout << 1;
	}else
	cout << 0;
	if(r1==x1 && pai(r2, x2))
	cout << 1;
	else cout << 0;
	if(r1==x1 && pai(r2, x2) && is_s(r2[2],x2[2]))
	cout << 1;
	else cout << 0;
	if(r1==x1 && pai(r2, x2) && is_s(r2[2],x2[2]) && is_xiangl(r2[2],x2[2]))
	cout << 1;
	else cout << 0;
	return 0;
}
