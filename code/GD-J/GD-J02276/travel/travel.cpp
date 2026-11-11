#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
bool cmp(char a1[], char b1[], int n){
	for(int i = 0;i < n;i++){
		if(a1[i] != b1[i]){
			return 0;
		}
	}
	return 1;
}
bool cmp(char a1[], char b1, int n){
	for(int i = 0;i < n;i++){
		if(a1[i] != b1){
			return 0;
		}
	}
	return 1;
}
ifstream In("travel.in");
ofstream Out("travel.out");
int main(){
	string c1,s1,c2,s2;
	In >> c1 >> s1 >> c2 >> s2;
	char p1[2], p2[2];
	for(int i = 0;i < 2;i++){
		p1[i] = s1[i];
		p2[i] = s2[i];
	}
	if(c1 == c2){
		Out << "1";
		if(cmp(p1, p2, 2)){
			Out << "1";

			if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
				if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
					Out << "1";
					if (cmp(&s1[2], 'A', 1) && cmp(&s2[2], 'B', 1)){
						Out << "1";
					}else if(cmp(&s1[2], 'B', 1) && cmp(&s2[2], 'A', 1)){
						Out << "1";
					}else if(cmp(&s1[2], 'B', 1) && cmp(&s2[2], 'C', 1)){
						Out << "1";
					}else if(cmp(&s1[2], 'C', 1) && cmp(&s2[2], 'B', 1)){
						Out << "1";
					}else{
						Out << "0";
					}
				}else{
					Out << "00";
				}
			}
			if(cmp(&s1[2], 'D', 1) || cmp(&s1[2], 'F', 1)){
				if(cmp(&s2[2], 'D', 1) || cmp(&s2[2], 'F', 1)){
					Out << "1";
					if(cmp(&s1[2], 'D', 1) && cmp(&s2[2], 'F', 1)){
						Out << "1";
					}
					else if(cmp(&s1[2], 'F', 1) && cmp(&s2[2], 'D', 1)){
						Out << "1";
					}else{
						Out << "0"; 
					}
				}else{
					Out << "00";
				}
			}
		}else{
			Out << "000";
		}
	}else{
		Out << "0000";
	}
	return 0;
}
