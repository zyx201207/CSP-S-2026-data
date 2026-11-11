#include<bits/stdc++.h> 
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3){
		cout << "0000";
		return 0;
	}
	else{
		for(int i = 0;i <= 1;i++){
			if(s2[i] != s4[i]){
				cout << "1000";
				return 0;
			}
		}
		if(s2[2]!='D' || s2[2]!='F'){
			if(s4[2]=='D' || s4[2]=='F'){
				cout << "1100";
				return 0;
			}
			else if(s2[2]=='A' && s4[2]=='C'){
				cout << "1110";
				return 0;
			}
			else if(s2[2]=='C' && s4[2]=='A'){
				cout << "1110";
				return 0;
			}
			else cout << "1111";
		}
		else if(s2[2]=='D' || s2[2]=='F'){
			if(s4[2]!='D' || s4[2]!='F'){
				cout << "1100";
				return 0;
			}
			else cout << "1111";
		}
	}
	return 0;
}
