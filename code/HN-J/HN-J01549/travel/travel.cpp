#include <bits/stdc++.h>
using namespace std;
	string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1 == c2) cout << "1" ;
	else{
		cout << "0000" ;
		return 0;
	}
	int lr=s1[0]*10+s1[1],ls=s2[0]*10+s2[1];
	if(lr == ls) cout << "1" ;
	else{
		cout << "000" ;
		return 0;
	}
	int fr,fs;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') fr=1;
	else fr=0;
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') fs=1;
	else fs=0;
	if(fr == fs) cout << "1" ;
	else {
		cout << "00" ;
		return 0;
	}
	if(fr == 0){
		cout << "1" ;
	}else{
		char rr=s1[3],ss=s2[3];
		if(rr-ss == 1 || rr-ss == -1) cout << "1" ;
		else cout << "0" ;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
