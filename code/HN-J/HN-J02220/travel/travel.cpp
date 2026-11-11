#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]-64<=3&&s2[2]-64<=3||s1[2]-64>=4&&s2[2]-64>=4){
				if(abs(s1[2]-s2[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			} 
		}else{
			cout<<"1000";
		}
	}else {
		cout<<"0000";
		return 0;
	}
	return 0;
}

