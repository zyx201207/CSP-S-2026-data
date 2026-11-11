#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
	if(c2[1]==c4[1]){
		
		if(c2[2]=='A'&&c4[2]=='B'||c4[2]=='C'){
			if(c2[2]=='A'&&c4[4]=='B'||c2[2]=='B'&&c4[4]=='A'){
				cout<<"1111";
			}else if(c2[2]=='B'&&c4[4]=='C'||c2[2]=='C'&&c4[4]=='B'){
				cout<<"1111";
			}else if(c2[2]=='D'&&c4[2]=='F'||c2[2]=='F'&&c4[2]=='B'){
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		
		} else if(c2[2]=='D'&&c4[4]=='F'){
			cout<<"1111";
		}else{
			cout<<"1100";
		}
	}else{
		cout<<"1000";
	}
}else{
	cout<<"0000";
}
	return 0;
}

