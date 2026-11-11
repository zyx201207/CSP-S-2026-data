//GZ-J00108 黄瀚德
#include <iostream>
using namespace std;
int main{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	char c2,c4;
	int a1,a2,a3,a4;
	int t1,t2,t3,t4;
	cin >> c1 >> c2 >> c3 >>c4;
	if(c2(2) == 'D'||'F'){
		t3 = 0;
	}else{
		t3 = 1;
	}
	if(c4(2) == 'D'||'F'){
		t4 = 0;
	}else{
		t4 = 1;
	}
	if(c2(2) == 'D'){
		t1 = 1;
	}else if(c2(2) == 'F'){
		t1 = 0;
	}else if(c2(2) == 'C'){
		t1 = 2;
	}else if(c2(2) == 'B'){
		t1 = 3;
	}else{
		t1 = 4;
	}
	if(c4(2) == 'D'){
		t2 = 1;
	}else if(c4(2) == 'F'){
		t2 = 0;
	}else if(c4(2) == 'C'){
		t2 = 2;
	}else if(c4(2) == 'B'){
		t2 = 3;
	}else{
		t2 = 4;
	}
	if(c1 == c3){
		a1 = 1;
	}else{
		a1 = 0;
		a2 = 0;
		a3 = 0;
		a4 = 0;
		cout << "0000";
	}
	if(a1 == 1&&c2(0) == c4(0)&&c2(1) == c2(1)) {
		a2 = 1;
	}else{
		a2 = 0;
		a3 = 0;
		a4 = 0;
		cout << "1000";
	}
	if(a1 ==1&&a2==1&&t3 == t4){
		a3 = 1;
	}else{
		a3 = 0;
		a4 = 0;
		cout << "1100";
	}
	if(t1-t2==1||t1-t2==-1&&a3==1){
		a4 = 1;
		cout << "1111";
	}else{
		a4 = 0;
		cout << "1110";
	}
	return 0;
}
