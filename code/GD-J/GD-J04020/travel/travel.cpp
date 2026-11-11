#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream ifs("travel.in");
	ofstream ofs("travel.out");
	string s1,s2,s3,s4;
	ifs>>s1>>s2>>s3>>s4;
	if(s1==s3){
		ofs<<'1';
		if(s2[0]==s4[0] && s2[1]==s4[1]){
			ofs<<'1';
			char a=s2[2],b=s4[2];
			if((a<='C' && b<='C') || (a>'C' && b>'C')){
				ofs<<'1';
				if(b-1==a || a-1==b){
					ofs<<'1';
				}else ofs<<"0";
			}else ofs<<"00";
		}else ofs<<"000";
	}else ofs<<"0000";
	return 0;
}
