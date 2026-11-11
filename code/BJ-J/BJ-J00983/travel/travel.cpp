#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	int Rx , Xx , ques1 = 0 , ques2 = 0 , ques3 = 0, ques4 = 0;
	int Rl , Xl;
	char R , X;
	
	cin >> Rx >> Rl >> R >> Xx >> Xl >> X;
	if(Rx == Xx) {
		ques1 = 1;
		if(Rl == Xl && ques1 == 1) {
			ques2 = 1;
			if((R == 'F' && X == 'D') || (R == 'D' && X == 'F')) {ques3 = ques4 = 1;}
			else if((65 <= R && R <=67) && (65 <= X && X <=67)) {ques3 = 1; if(abs(X - R) == 1) ques4 = 1;}
		}
	}
	cout << ques1 << ques2 << ques3 << ques4;
	return 0;
}