//GZ-J00012 刘宝东 个人报名 
#include<bits/stdc++.h>
using namespace std;
string xa,xab,xb,xba;
int main(){
	freopen("travel.in","r","otdin")
	freopen("travel.out","w","otdout")
	cin >> xa >> xab >> xb >> xba;
	if(xa == xb){
		cout << 1;
	}else{
		cout << 0;
	}
	if(xab[0] == xab[0] && xab[1] == xba[1]){
		cout << 1;
	}else{
		cout << 0;
	}
	if(((xab[2] == "A" || xab[2] == "B" ||xab[2] == "C") && (xba[2] == "A" || xba[2] == "B" ||xba[2] == "C")) || (xab[2]=="D" || xab[2]=="F") &&(xba=="D" || xba == "F")){
		cout << 1;
	}else{
		cout << 0
	}
	cout << 0;
	return 0;
	
}
