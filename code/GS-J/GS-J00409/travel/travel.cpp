#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if(s1.substr(2,1)=="A"||s1.substr(2,1)=="B"||s1.substr(2,1)=="C"){
				if(s2.substr(2,1)=="A"||s2.substr(2,1)=="B"||s2.substr(2,1)=="C"){
					cout<<"1";
					if(s1.substr(2,1)=="A"&&s2.substr(2,1)=="B"||s1.substr(2,1)=="B"&&s2.substr(2,1)=="C"){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else{
				if(s2.substr(2,1)=="F"||s2.substr(2,1)=="D"){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
