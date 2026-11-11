#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	int c1,s1,c2,s2;
	char c,s;
	cin >> c1 >> c2 >> c >> s1 >> s2 >> s;
	if(c1!=s1){
		cout << "0000";
		return 0;
	}
	cout << 1;
	if(c2!=s2){
		cout << "000";
		return 0;
	}
	cout << 1;
	if((c=='A' || c=='B' || c=='C') && (s=='D' || s=='F')){
		cout << "00";
		return 0;
	}else if((c=='D' || c=='F') && (s=='A' || s=='B' || s=='C')){
		cout << "00";
		return 0;
	}
	cout << 1;
	if(c+1==s || s+1==c)cout << 1;
	else cout << 0;
	
	return 0;
} 
