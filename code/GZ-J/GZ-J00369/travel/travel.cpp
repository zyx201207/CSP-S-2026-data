//GZ-J00369 Íõ×ÓÇ¬
#include<bits/stdc++.h>
using namespace std;

string a,b,x,y;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> x >> y;
	if(a==x){
		cout << "1";
	}
	if(a!=x){
		cout << "0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1]){
		cout << "1";
	}
	if(b[0]!=y[0]||b[1]!=y[1]){
		cout << "000";
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&y[2]>='A'&&y[2]<='C'){
		cout << "1";
	}
	if(b[2]>='D'&&b[2]<='F'&&y[2]>='D'&&y[2]<='F'){
		cout << "1";
	}
	if(b[2]>='A'&&b[2]<='C'&&y[2]>='D'&&y[2]<='F'||b[2]>='D'&&b[2]<='F'&&y[2]>='A'&&y[2]<='C'){
		cout << "00";
		return 0;
	}
	if(b[2]+1==y[2]||b[2]==y[2]+1){
		cout << "1";
	}
	else{
		cout << "0";
	}
	return 0;
}
