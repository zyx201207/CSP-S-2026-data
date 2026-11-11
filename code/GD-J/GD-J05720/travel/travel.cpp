#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	string c1,s1,c2,s2;
	int q1=0,q2=0,q3=0,q4=0;
	fin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		q1=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
		q2=1;
			if(s1.substr(2,1)=="D"||s1.substr(2,1)=="F"){
				if(s2.substr(2,1)!=s1.substr(2,1)&&(s2.substr(2,1)=="D"||s2.substr(2,1)=="F")){
					q3=1;
					q4=1;
				}
				else{
					q3=0;
					q4=0;
				}
			}
			else{
				if(s2.substr(2,1)!=s1.substr(2,1)&&(s2.substr(2,1)=="A"||s2.substr(2,1)=="B"||s2.substr(2,1)=="C")){
					q3=1;
					if(s2.substr(2,1)=="B"){
						q4=1;
					}
					else{
						if(s1.substr(2,1)=="B"){
							q4=1;
						}
						else{
							q4=0;
						}
					}
				}
				else{
					q3=0;q4=0;
				}
			}
	}
	else{
		q2=0;
		q3=0;
		q4=0;
	}
	}
	else{
		q1=0;
		q2=0;
		q3=0;
		q4=0;
	}
	fout<<q1<<q2<<q3<<q4;
	fin.close();
	fout.close();
	return 0;
}
