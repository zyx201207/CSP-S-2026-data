#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string l1 = s1.substr(2, 1),l2 = s2.substr(2, 1);
	if (c1 == c2){
		cout<<"1";
		if (s1.substr(0, 2) == s2.substr(0, 2)){
			cout<<"1";
			if (((l1 == "A" || l1 == "B" || l1 == "C") && (l2 == "A" || l2 == "B" || l2 == "C")) || ((l1 == "E" || l1 == "F") && (l2 == "E" || l2 == "F" ))){
				cout<<"1";
				if ((l1 == "A" && l2 == "B") || (l1 == "B" && (l2 == "A" || l2 == "C")) || (l1 == "E" && l2 == "F") || (l1 == "F" && l2 == "E")){
					cout<<"1";
				}else{
					cout<<"0";	
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
