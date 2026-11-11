#include<bits/stdc++.h>
using namespace std;
string v1,z1,v2,z2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>v1>>z1>>v2>>z2;
	if(v1!=v2) {
		cout<<"0000";
		return 0;
	}else{
	
	if(z1[0]==z2[0]&&z1[1]==z2[1]) {
		if(z1[2]-'A'<3&&z2[2]-'A'<3||z1[2]-'A'>2&&z2[2]-'A'>2) {
			if(z1[2]-'A'+1==z2[2]-'A'||z1[2]-'A'-1==z2[2]-'A') {
				cout<<"1111";
				return 0;
			} else{
				cout<<"1110";
				return 0;
			}
				
		} else {
			cout<<"1100";
			return 0;
		}
	} else {
		cout<<"1000";
		return 0;
	}
}
	return 0;
}
