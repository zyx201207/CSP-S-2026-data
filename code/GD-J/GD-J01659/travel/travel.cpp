#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int check(string s){
	if(s[2]>='A' && s[2]<='C') return 1;
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	
	bool flag=1;
	for (int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) flag=0;
	}
	
	if(flag){
		cout << 1;
		if(check(s1)==check(s2)){
			cout << 1;
			if(check(s1)==0) cout << 1;
			else if(s1[2]+1==s2[2] || s2[2]+1==s1[2]){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else{
			cout << "00";
			return 0;
		}
	}
	else{
		cout << "000";
	}
	
	return 0;
} 
