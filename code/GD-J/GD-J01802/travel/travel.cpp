#include<bits/stdc++.h> 
using namespace std;

string in1, in2;
int train1, train2;
int row1, row2;
char weat1, weat2;
bool flag1, flag2, flag3, flag4;

bool check(char a, char b){
	bool fl1  = false, fl2 = false;
	if(a >= 'A' && a <= 'C') fl1 = true;
	if(b >= 'A' && b <= 'C') fl2 = true;
	return fl1 == fl2;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> in1;
	train1 = (in1[0] - '0') * 10 + in1[1] - '0';
	cin >> in1;
	row1 = (in1[0] - '0') * 10 + in1[1] - '0', weat1 = in1[2];
	cin >> in2;
	train2 = (in2[0] - '0') * 10 + in2[1] - '0';
	cin >> in2;
	row2 = (in2[0] - '0') * 10 + in2[1] - '0', weat2 = in2[2];
/*
	cout << train1 << " " << row1 << " " << weat1 << "\n";
	cout << train2 << " " << row2 << " " << weat2 << "\n";
*/
	if(train1 == train2){
		flag1 = true;
		if(row1 == row2){
			flag2 = true;
			if(check(weat1, weat2)){
				flag3 = true;
				if(weat1 - weat2 == 1 || weat1 - weat2 == -1)
				flag4 = true;
			}
		}
	}
	cout << flag1 << flag2 << flag3 << flag4;
}
