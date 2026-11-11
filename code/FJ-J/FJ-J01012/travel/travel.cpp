#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,s1,s2,c2;
	char n1,n2;
    cin >> c1 >> s1 >> n1 >> c2 >> s2 >> n2;
    cout << (c1==c2);
    cout << (c1==c2 && s1==s2);
    if(!(c1==c2 && s1==s2)){
    	cout << "00";
    	return 0;
	}
	if(n1=='A'){
		if(n2=='B') cout << "11";
		else if(n2=='C') cout << "10";
		else cout << "00";
	}
	else if(n1=='B'){
		if(n2=='A' || n2=='C') cout << "11";
		else cout << "00";
	}
	else if(n1=='C'){
		if(n2=='B') cout << "11";
		else if(n2=='A') cout << "10";
		else cout << "00";
	}
	else if(n1=='D'){
		if(n2=='F') cout << "11";
		else cout << "00";
	}
	else if(n1=='F'){
		if(n2=='D') cout << "11";
		else cout << "00";
	}
	return 0;
}
