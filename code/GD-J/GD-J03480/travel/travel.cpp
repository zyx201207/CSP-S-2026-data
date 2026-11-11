#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sa = 0,sb = 0,sc = 0,sd = 0,a,c;
	string b,d;
	cin >> a >> b >> c >> d;
	if(a == c){
		sa = 1;
		if(b[0] == d[0]&&b[1] == d[1]){
		    sb = 1;
			if(b[3] == 'A'&&d[3] == 'B'||b[3] == 'B'&&d[3] == 'A'||b[3] == 'C'&&d[3] == 'B'||b[3] == 'B'&&d[3] == 'C'||b[3] == 'D'&&d[3] == 'F'||b[3] == 'F'&&d[3] == 'D'){
				sc = 1;
				sd = 1;
        	}
        	if(b[3] == 'C' && d[3] == 'A'||b[3] == 'A' && d[3] == 'C'){
        		sc = 1;
			}
    	}
	}
	cout << sa << sb << sc << sd;
	return 0;
}
