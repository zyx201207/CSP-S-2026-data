#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="";
	cin >> c1 >> s1 >> c2 >> s2;
	bool f=1;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			f=0;
			break;
		}
	}
	if(f) ans+="1";
	else{
		cout << "0000\n";
		return 0; 
	}
	f=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f=0;
			break;
		}
	}
	if(f) ans+="1";
	else{
		cout << ans << "000\n";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		if(s1[1]==s2[1]){
			ans+="1";
			if(s1[2]==s2[2]-1) ans+="1";
			else if(s1[2]==s2[2]+1) ans+="1";
			else ans+="0"; 
		}else ans+="00";
	}else if(s1[2]>'C'&&s2[2]>'C'){
		if(s1[1]==s2[1]){
			ans+="1";
			if(s1[2]==s2[2]-1) ans+="1";
			else if(s1[2]==s2[2]+1) ans+="1";
			else ans+="0";
		}else ans+="00";
	}else ans+="00";
	cout << ans << "\n";
	return 0;
}
