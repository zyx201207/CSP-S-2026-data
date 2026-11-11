#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string C1,S1,C2,S2;
	cin >> C1 >> S1 >> C2 >> S2;
	bool f = true;
	//判断同一节车厢 
	if(C1 == C2) cout << 1;
	else{
		f = false;
		cout << 0;
	}
	//判断同一节车厢的同一排 
	int s1 = 0,s2 = 0,pos = 0;
	while(pos < 2){
		s1 = s1 * 10 + (S1[pos] - '0');
		s2 = s2 * 10 + (S2[pos] - '0');
		pos++;
	}
	if(s1 == s2 && f == true) cout << 1;
	else{
		f = false;
		cout << 0;
	}
	//判断同一节车厢的同一侧  
	int t1 = 0,t2 = 0;
	if(S1[2] == 'A' || S1[2] == 'B' || S1[2] == 'C') t1 = 1;
	else t1 = 2;
	if(S2[2] == 'A' || S2[2] == 'B' || S2[2] == 'C') t2 = 1;
	else t2 = 2;
	if(t1 == t2 && f == true) cout << 1;
	else{
		f = false;
		cout << 0;
	}
	//判断座位相邻
	int a = S1[2] - 'A';
	int b = S2[2] - 'A';
	if(f == true && abs(a - b) == 1){
		cout << 1;
	}
	else if(f == true && (S1[2] == 'D' && S2[2] == 'F') || (S1[2] == 'D' && S2[2] == 'F')){
		cout << 1;
	}
	else{
		f = false;
		cout << 0;
	}
	return 0;
}
