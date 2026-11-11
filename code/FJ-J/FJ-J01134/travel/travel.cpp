#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	string c1;//车厢号 
	string c2;
	string s1;//座位号 
	string s2;
	fin >> c1 >> s1 >> c2 >> s2;
//	cin >> c1 >> s1 >> c2 >> s2;
	char code1 = s1[2];
	char code2 = s2[2];
	string pai1;
	string pai2;
	for(int i = 0;i < 2;i++){
		pai1 += s1[i];
		pai2 += s2[i];
	}
	
//	cout << code1 << " " << code2;
	//不同的车厢直接否决 
	if(c1 != c2){
		fout << "0000";
//		cout << "0000";
		return 0;
	}else{
		fout << "1";
//		cout << "1";
	}
	//相同车厢 
	//判断是否同一排
	if(pai1 == pai2){
		fout << "1";
//		cout << "1";
		//是否在同一侧
		if(code1 >= 'A'&& code1 <= 'C' && code1 >= 'A' && code2 <= 'C'){
			//A-C侧 
			fout << "1";
//			cout << "1";
			//AB 
			if((code1 == 'A' && code2 == 'B') || (code2 == 'A' && code1 == 'B')){
				fout << "1";
//				cout << "1";
			}else if((code1 == 'B' && code2 == 'C') || (code2 == 'B' && code1 == 'C')){
				//BC
				fout << "1";
//				cout << "1";
			}else{
				fout << "0";
//				cout << "0";
			}
		
		}else if(code1 >= 'D'&& code1 <= 'F' && code1 >= 'D' && code2 <= 'F'){
			//DF侧：一定相邻
			fout << "11";
//			cout << "11";
			return 0; 
		}else{
			//不同侧 
			fout << "00";
//			cout << "00";
			return 0;
		}
	}else{
		//否则之后全0 
		fout << "000";
//		cout << "000";
		return 0; 
	}
	return 0;
} 
