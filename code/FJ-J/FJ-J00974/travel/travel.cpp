#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3){
         cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	
	if(s2[1]==s4[1] && s2[0]==s4[0]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	
	int k1, k2;
	if(s2[2]>='A' && s2[2]<='C')k1 = 1;
	else k1 = 2;
	if(s4[2]>='A' && s4[2]<='C')k2 = 1;
	else k2 = 2;
	if(k1==k2){
		cout << "1";
	}else if(k1!=k2){
		cout << "00";
		return 0;
	}
	if(s2[2]-s4[2]==1 || s2[2]-s4[2]==-1){
		cout << "1";
	}else cout << "0";
	return 0; 
}
