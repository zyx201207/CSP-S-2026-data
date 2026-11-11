#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1 = false,f2 = false,f3 = false,f4 = false;
	if(c1 == c2){
		f1 = true;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f1 && s1[0] == s2[0] && s1[1] == s2[1]){
		f2 = true;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f1 && f2){
		if(s1[2] <= 'C' && s2[2] <= 'C'){
			f3 = true;
			cout<<"1";
		}else if(s1[2] > 'C' && s2[2] > 'C'){
			f3 = true;
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(f1 && f2 && f3){
		if(s1[2] > 'C' && s2[2] > 'C'){
			f4 = true;
			cout<<"1";
		}else if(s1[2] <= 'C' && s2[2] <= 'C'){
			if(s1[2] == 'C' && s2[2] == 'A'){
				cout<<"0";
			}else if(s1[2] == 'A' && s2[2] == 'C'){
				cout<<"0";
			}else{
				f4 = true;
				cout<<"1";
			}
		}
	}else{
		cout<<"0";
	}
	return 0;
} 
