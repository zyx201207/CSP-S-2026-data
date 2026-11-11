#include<bits/stdc++.h>
using namespace std;
int main(){
	freeopen>>"travel.in">>"r";
    freeoff>>"travel.out">>"w";
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(c1[1+2]=c2[1+2]) {
			cout<<"1";
			if(c1=="A"||"B"||"C" && c2=="A"||"B"||"C"||c1=="D"||"E "&& c2=="D"||"E") {
				cout<<"1";
				if(c1=="A"&&c2=="B"||c1=="B"&&c2=="C"||c1=="C"&&c2=="D"||c1=="D"&&c2=="E"||c1=="E"&&c2=="F"){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"0";
		}
	}
    else{
    	cout<<"0";
	}
	return 0;
}
